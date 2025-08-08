import os
import gzip
from urllib.parse import unquote


def extract_coredump(input_file: str, output_file: str):
    with open(input_file, "rb") as gz_file, open(output_file, "wb") as out_file:
        decompressed_data = gzip.decompress(gz_file.read())
        out_file.write(decompressed_data)
    return output_file


def find_app_path_from_coredump_file(apps_path, coredump_file):
    parsed_name = os.path.basename(coredump_file).split(".")
    if len(parsed_name) > 2:
        for app in apps_path:
            if parsed_name[2] in os.path.basename(app):
                return app
    return None


def collect_coredump_data():
    coredump_files_gz = [
        "/home/dodintsova/Documents/coredumps/extract/coredump.1740702141.AdMake80msAsilBComHandler.426128.core.gz",
        "/home/dodintsova/Documents/coredumps/extract/coredump.1740704758.AdMake80msAsilBComHandler.397455.core.gz",
        "/home/dodintsova/Documents/coredumps/extract/coredump.1740695772.AdMake80msAsilBComHandler.639112.core.gz",
    ]

    all_apps_paths = ["ipnext_apps_debug/AdMake80msAsilBComHandler-ST-46b881c409f7"]

    for file in coredump_files_gz:
        if find_app_path_from_coredump_file(all_apps_paths, file):
            print(file)
            try:
                extract_coredump(file, file[:-3])
            except:
                print("Failure extraction:", file)
                continue
        else:
            print("Not found:", file)


if __name__ == "__main__":
    collect_coredump_data()