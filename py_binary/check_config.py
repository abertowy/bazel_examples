import json
# 1001 : "deadline"
# 1002 : "alive"
# 1003 : "logical"

# entity = function_group = CustomerApplicationId + 100X-> local_supervision_id
# positioning_engine_application = "CountryVariant" = 50
# positioning_engine_china_application = "CountryVariant" = 60
# positioning_engine_china_monitor_application = "CountryVariant" = 70
# crash_reporter_ara_proxy = "MachineFG" = 80
# ad_make_80ms_asil_b_com_handler = "Driving" = 100
# ad_make_40ms_asil_b = "Driving" = 200
# ad_make_40ms_asil_b_low_level_perception = "Driving" = 300
# ad_make_1000ms_asil_b = "Driving" = 400
# frameserver_proxy_application = "MachineFG" = 4100
# iks_service_app = "IKS" = 4200
# cv_minion = "Driving" = 4400
# mrr_tracker = "MRR" = 4500
# srr_tracker = "SRR" = 4600


def check_config():
    with open("/home/dodintsova/work_dir/ddad/ecu/xpad/xpad-shared/config/ipnext/isoc/ara/phm/full/phm_config.json") as f:
        json_content = json.loads(f.read())

    local_supervisions = json_content["local_supervisions"]

    fg_data = []
    for local_supervision in local_supervisions:
        supervision_types = []
        for supervision in local_supervision["supervisions"]:
            supervision_types.append(supervision["supervision_type"])
        fg_data.append(
            {
                "local_supervision_id": local_supervision["local_supervision_id"],
                "function_group": local_supervision["function_group"],
                "function_group_state_groups": local_supervision["function_group_state_groups"],
                "supervision_types": supervision_types,
            }
        )
    with open("result_config.json", "w") as f:
        json.dump(fg_data, f, indent=2)


if __name__ == "__main__":
    check_config()