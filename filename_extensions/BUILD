load("@bazel_skylib//rules:common_settings.bzl", "bool_flag", "string_flag")
load("@bazel_skylib//lib:selects.bzl", "selects")
load("//filename_extensions:rule.bzl", "extension_rule")
load("//filename_extensions:swes.bzl", "ipn_main_swes", "ipn_main_swfl", "pdx_logistics")
load("//filename_extensions:logistics.bzl", "logistics", "logistics_map", "app_ids")

config_setting(
    name = "signing_enabled",
    flag_values = {
        ":signing": "true",
    },
)

config_setting(
    name = "signing_disabled",
    flag_values = {
        ":signing": "false",
    },
)

bool_flag(
    name = "signing",
    build_setting_default = False,
)

config_setting(
    name = "production_enabled",
    flag_values = {
        ":production": "true",
    },
)

config_setting(
    name = "production_disabled",
    flag_values = {
        ":production": "false",
    },
)

bool_flag(
    name = "production",
    build_setting_default = False,
)


selects.config_setting_group(
    name = "production_signing_enabled",
    match_all = [":signing_enabled",":production_enabled"],
)

selects.config_setting_group(
    name = "only_production",
    match_all = [":signing_disabled",":production_enabled"],
)

selects.config_setting_group(
    name = "only_signing",
    match_all = [":signing_enabled",":production_disabled"],
)

extension_rule(
    name = "simple_extension",
    filename = select({
        ":signing_enabled": logistics["container_idx"] + ".txt",
        "//conditions:default": logistics["container_idx_testkeys"] + ".txt",
    }),
    visibility = ["//visibility:public"],
)

extension_rule(
    name = "complex_extension",
    # ERROR
    app = select({
        "//filename_extensions:signing_enabled": logistics_map["app1"]["name"],
        "//conditions:default": logistics_map["app1"]["name"],
    }) + ".sign",
    # app = select({
    #     "//filename_extensions:signing_enabled": logistics_map["app1"]["name"],
    #     "//conditions:default": logistics_map["app2"]["name"],
    # }),
    ids = app_ids,
    filename = select({
        ":production_signing_enabled": logistics["container_idx"] + "__" + logistics["extension"] + ".txt",
        ":only_signing": logistics["container_idx"] + ".txt",
        ":only_production": logistics["container_idx_testkeys"] + "__" + logistics["extension"] + ".txt",
        "//conditions:default": logistics["container_idx_testkeys"] + ".txt",
    }),
    visibility = ["//visibility:public"],
)
