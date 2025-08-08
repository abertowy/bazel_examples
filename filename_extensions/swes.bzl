"""
this lists all the logistic information for all SWEs of a soc
"""
swe_versions = {
    "app": "010_046_001",
    "app2": "010_046_001",
    "bl": "020_005_001",
    "cal": "010_046_001",
    "swt_alt_cfg_swfl": "010_046_001",
    "swt_swfl": "010_046_001",
}

swe_sgbmids = {
    "app": "0000C275",
    "app2": "0000C85E",
    "bl": "0000C258",
    "cal": "0000C276",
    "swt_alt_cfg_swfl": "0000C278",
    "swt_swfl": "0000C277",
}

swe_sgbmids_testkeys = {
    "app": "0000AD06",
    "app2": "0000D2D0",
    "bl": "0000ACF1",
    "cal": "0000AD07",
    "swt_alt_cfg_swfl": "0000AD09",
    "swt_swfl": "0000AD08",
}

swe_versions_ipn15 = {
    "app": "010_029_001",
    "app2": "010_029_001",
    "bl": "020_005_001",
    "cal": "010_029_001",
    "swt_alt_cfg_swfl": "010_029_001",
    "swt_swfl": "010_029_001",
}

swe_sgbmids_ipn15 = {
    "app": "0000FC16",
    "app2": "0000FC13",
    "bl": "0000FC02",
    "cal": "0000FC17",
    "swt_alt_cfg_swfl": "0000FC15",
    "swt_swfl": "0000FC14",
}

swe_sgbmids_testkeys_ipn15 = {
    "app": "0000FC1D",
    "app2": "0000FC26",
    "bl": "0000FC01",
    "cal": "0000FC1E",
    "swt_alt_cfg_swfl": "0000FC2E",
    "swt_swfl": "0000FC1F",
}

# For SBOM
fw_version = {
    "moduleName": "switch_firmware",
    "moduleVersion": "24.0.1.0",  # Should match the value in ipnext_dependencies.bzl
    "vendor": "Valeo",
}
swe_logistics = {
    "app": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["app"],
            "//conditions:default": swe_sgbmids["app"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["app"],
            "//conditions:default": swe_versions["app"],
        }),
    },
    "app2": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["app2"],
            "//conditions:default": swe_sgbmids["app2"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["app2"],
            "//conditions:default": swe_versions["app2"],
        }),
    },
    "bl": {
        "processclass": "btld",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["bl"],
            "//conditions:default": swe_sgbmids["bl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["bl"],
            "//conditions:default": swe_versions["bl"],
        }),
    },
    "cal": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["cal"],
            "//conditions:default": swe_sgbmids["cal"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["cal"],
            "//conditions:default": swe_versions["cal"],
        }),
    },
    "swt_alt_cfg_swfl": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["swt_alt_cfg_swfl"],
            "//conditions:default": swe_sgbmids["swt_alt_cfg_swfl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["swt_alt_cfg_swfl"],
            "//conditions:default": swe_versions["swt_alt_cfg_swfl"],
        }),
    },
    "swt_swfl": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_ipn15["swt_swfl"],
            "//conditions:default": swe_sgbmids["swt_swfl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["swt_swfl"],
            "//conditions:default": swe_versions["swt_swfl"],
        }),
    },
}

swe_logistics_testkeys = {
    "app": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["app"],
            "//conditions:default": swe_sgbmids_testkeys["app"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["app"],
            "//conditions:default": swe_versions["app"],
        }),
    },
    "app2": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["app2"],
            "//conditions:default": swe_sgbmids_testkeys["app2"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["app2"],
            "//conditions:default": swe_versions["app2"],
        }),
    },
    "bl": {
        "processclass": "btld",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["bl"],
            "//conditions:default": swe_sgbmids_testkeys["bl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["bl"],
            "//conditions:default": swe_versions["bl"],
        }),
    },
    "cal": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["cal"],
            "//conditions:default": swe_sgbmids_testkeys["cal"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["cal"],
            "//conditions:default": swe_versions["cal"],
        }),
    },
    "swt_alt_cfg_swfl": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["swt_alt_cfg_swfl"],
            "//conditions:default": swe_sgbmids_testkeys["swt_alt_cfg_swfl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["swt_alt_cfg_swfl"],
            "//conditions:default": swe_versions["swt_alt_cfg_swfl"],
        }),
    },
    "swt_swfl": {
        "processclass": "swfl",
        "sgbmid": select({
            "//filename_extensions:production_enabled": swe_sgbmids_testkeys_ipn15["swt_swfl"],
            "//conditions:default": swe_sgbmids_testkeys["swt_swfl"],
        }),
        "version": select({
            "//filename_extensions:production_enabled": swe_versions_ipn15["swt_swfl"],
            "//conditions:default": swe_versions["swt_swfl"],
        }),
    },
}

ipn10_main_swes = " ".join([val for val in swe_sgbmids.values()])
ipn10_main_swfl = " ".join([swe_sgbmids[key] for key in swe_sgbmids if key != "bl"])
ipn10_main_swes_testkeys = " ".join([val for val in swe_sgbmids_testkeys.values()])
ipn10_main_swfl_testkeys = " ".join([swe_sgbmids_testkeys[key] for key in swe_sgbmids_testkeys if key != "bl"])

ipn15_main_swes = " ".join([val for val in swe_sgbmids_ipn15.values()])
ipn15_main_swfl = " ".join([swe_sgbmids_ipn15[key] for key in swe_sgbmids_ipn15 if key != "bl"])
ipn15_main_swes_testkeys = " ".join([val for val in swe_sgbmids_testkeys_ipn15.values()])
ipn15_main_swfl_testkeys = " ".join([swe_sgbmids_testkeys_ipn15[key] for key in swe_sgbmids_testkeys_ipn15 if key != "bl"])

ipn_main_swes = select({
    "//filename_extensions:production_enabled": ipn15_main_swes,
    "//conditions:default": ipn10_main_swes,
})
ipn_main_swfl = select({
    "//filename_extensions:production_enabled": ipn15_main_swfl,
    "//conditions:default": ipn10_main_swfl,
})
ipn_main_swes_testkeys = select({
    "//filename_extensions:production_enabled": ipn15_main_swes_testkeys,
    "//conditions:default": ipn10_main_swes_testkeys,
})
ipn_main_swfl_testkeys = select({
    "//filename_extensions:production_enabled": ipn15_main_swfl_testkeys,
    "//conditions:default": ipn10_main_swfl_testkeys,
})

baureihenverbuende = ["NA05", "G065", "G070", "NA00", "NA06", "RR45"]
diagaddress = 0x90
ee_component_ipn10 = "IPN10-MAIN"
ee_component_ipn15 = "IPN15-MAIN"
basevariant = "IPN_M"
version = select({
    "//filename_extensions:production_enabled": "010_029_001",
    "//conditions:default": "010_046_001",
})
container_idx = select({
    "//filename_extensions:production_enabled": ee_component_ipn15.replace("-", "__") + "__" + baureihenverbuende[0],
    "//conditions:default": ee_component_ipn10.replace("-", "__") + "__" + baureihenverbuende[0],
})
container_idx_testkeys = container_idx  # as long as CI is not ready for hot keys + "_TESTK"
err_injection = "_ERRORINJ"

pdx_logistics = {
    "basevariant": basevariant,
    "baureihenverbuende": baureihenverbuende,
    "container_idx": container_idx,
    "container_idx_testkeys": container_idx_testkeys,
    "containername": container_idx + "." + version,
    "containername_error_inj": container_idx + err_injection + "." + version,
    "containername_testkeys": container_idx_testkeys + "." + version,
    "containername_testkeys_error_inj": container_idx_testkeys + err_injection + "." + version,
    "diagaddress": diagaddress,
    "ee_component": select({
        "//filename_extensions:production_enabled": ee_component_ipn15,
        "//conditions:default": ee_component_ipn10,
    }),
}