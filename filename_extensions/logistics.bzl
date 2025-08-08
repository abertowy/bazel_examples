component = "MAIN"
suffix = ["AA01", "BB02"]
version = "010_000_255"
container_idx = component + "__" + suffix[0]
container_idx_testkeys = component + "__" + suffix[1]
extension = "PRODUCTION"

logistics_aa = {
    "app1":"APP_1_AA",
    "app2": "APP_2_AA",
}

logistics_bb = {
    "app1": "APP_1_BB",
    "app2": "APP_2_BB",
}

ids_aa = {
    "app1":"00A1",
    "app2": "00A2",
    "app3": "00A3",
}

ids_bb = {
    "app1": "00B1",
    "app2": "00B2",
    "app3": "00B3",
}

logistics_map = {
    "app1": {
        "name": select({
            "//filename_extensions:production_enabled": logistics_bb["app1"],
            "//conditions:default": logistics_aa["app1"],
        }),
        "id": select({
            "//filename_extensions:production_enabled": ids_bb["app1"],
            "//conditions:default": ids_aa["app1"],
        }),
    },
    "app2": {
        "name": select({
            "//filename_extensions:production_enabled": logistics_bb["app2"],
            "//conditions:default": logistics_aa["app2"],
        }),
        "id": select({
            "//filename_extensions:production_enabled": ids_bb["app2"],
            "//conditions:default": ids_aa["app2"],
        }),
    }
}


app_ids_aa = " ".join([val for val in ids_aa.values()])
app_ids_bb = " ".join([ids_bb[key] for key in ids_bb if key != "app3"])
app_ids = select({
    "//filename_extensions:production_enabled": app_ids_bb,
    "//conditions:default": app_ids_aa,
})

logistics = {
    "container_idx": container_idx,
    "container_idx_testkeys": container_idx_testkeys,
    "containername": container_idx + "." + version,
    "component": component,
    "extension": extension,
}