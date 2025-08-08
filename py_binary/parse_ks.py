import xml.etree.ElementTree as ET
import argparse
from typing import List


class NonExistentSgbmId(Exception):
    """
    Raise this exception when a SGBM id doesn't exist in the Konstruktiver
    Stand.
    """


class NonExistentVersion(Exception):
    """
    Raise this exception when a SGBM version doesn't exist in the Konstruktiver
    Stand.
    """


class NonUniqueVersion(Exception):
    """
    Raise this exception when a SGBM version is not unique.
    """


class DifferentSgbmIdVersioning(Exception):
    """
    Raise this exception when multiple versions of the same SGBM id are found
    in the Konstruktiver Stand.
    """


def parse_hex(num):
    """
    Parse hex number as int.
    """
    return int(num, 16)

def parse_ks_matthias(ks_path, sgbmid, part_numbers: List[str]):
    """
    Parse Prozessklasse and SGBM Version numbers from Konstruktiver Stand.
    """
    root = ET.parse(ks_path).getroot()
    try:
        _class = root \
            .find(f'sgbmNummern/sgbmNummer[@nummer="{sgbmid:X}"]') \
            .attrib['prozessklasse']

        majors = set()
        minors = set()
        patches = set()

        for part_number in part_numbers:
            print("Sachnummer:", f'{part_number:X};', "SGBMID:", f'{sgbmid:X}')
            attrs = root \
                .find((
                    'ks/softwareInstanzen/'
                    f'softwareInstanz[@sachnummer="{part_number:X}"]/'
                    f'technischeEinheiten/technischeEinheit[@sgbmNummer="{sgbmid:X}"]'
                )) \
                .attrib

            majors.add(int(attrs['hv']))
            minors.add(int(attrs['uv']))
            patches.add(int(attrs['pv']))

        if len(majors) > 1 or len(minors) > 1 or len(patches) > 1:
            raise DifferentSgbmIdVersioning(
                f"Multiple versions of the same SGBM id: {sgbmid:X} "
                f"and part numbers: {part_numbers:X} found in Konstruktiver Stand: "
                f"majors: {majors}, minors: {minors}, patches: {patches}"
            )

        return {
            "class": _class,
            "version": (int(attrs['hv']), int(attrs['uv']), int(attrs['pv']))
        }
    except AttributeError as caught:
        msg = f"SGBM id {sgbmid:X} not found in Konstruktiver Stand: {ks_path} and part numbers: {part_numbers}"
        raise NonExistentSgbmId(msg) from caught


def parse_ks(ks_path, sgbmid, sachnummern: List[str]):
    """
    Parse Prozessklasse and SGBM Version numbers from Konstruktiver Stand.
    """
    root = ET.parse(ks_path).getroot()

    try:
        _class = root.find(f'sgbmNummern/sgbmNummer[@nummer="{sgbmid:X}"]').attrib["prozessklasse"]
        attrs = []
        for item in sachnummern:
            attrs += root.findall(f'ks/softwareInstanzen/softwareInstanz[@sachnummer="{item:X}"]/technischeEinheiten/technischeEinheit[@sgbmNummer="{sgbmid:X}"]')
        versions = set()
        for item in attrs:
            versions.add((int(item.attrib["hv"]), int(item.attrib["uv"]), int(item.attrib["pv"])))
        if len(versions) > 1:
            msg = f"Version for SGBM id {sgbmid:X} is not unique in Konstruktiver Stand: {ks_path}"
            raise NonUniqueVersion(msg)
        elif len(versions) < 1:
            msg = f"Version for SGBM id {sgbmid:X} is not found in Konstruktiver Stand: {ks_path}"
            raise NonExistentVersion(msg)
        return {"class": _class, "version": versions.pop()}
    except AttributeError as caught:
        msg = f"SGBM id {sgbmid:X} not found in Konstruktiver Stand: {ks_path}"
        raise NonExistentSgbmId(msg) from caught


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ks_file", required=True, help="Location of ks file")
    parser.add_argument("--sachnummern", required=True, nargs="+", help="List of sachnummern")
    parser.add_argument("--sgbmids", required=True, nargs="+", help="List of swes sgbmid")
    args = parser.parse_args()

    for sgbmid in args.sgbmids:
        sgbmid_hex = parse_hex(sgbmid)
        sachnummern = []
        for item in args.sachnummern:
            sachnummern.append(parse_hex(item))

        ks_info = parse_ks(args.ks_file, sgbmid_hex, sachnummern)
        # ks_info = parse_ks_matthias(args.ks_file, sgbmid_hex, sachnummern)

        # Get version from Konstruktiver Stand.
        swe_version = ks_info["version"]
        swe_version = (swe_version[0], swe_version[1], 0)
        print(sgbmid, swe_version)


if __name__ == "__main__":
    main()