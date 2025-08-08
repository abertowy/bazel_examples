load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")
load("//filegroup:filegroup.bzl", "fg_resources", "LogInfo")

config_setting(
    name = "ipnext_enabled",
    flag_values = {
        ":ipnext": "true",
    },
)

bool_flag(
    name = "ipnext",
    build_setting_default = False,
)

[
    (
        filegroup(
            name = "binary_image_die" + number,
            srcs = [
            ],
        ),
    )
    for number in [
        "0",
        "1",
    ]
]

[
    (
        filegroup(
            name = "die" + number,
            srcs = select({
                "//filegroup:ipnext_enabled": [
                    "//expand_template:hello_world_template",
                ],
                "//conditions:default": [
                    ":binary_image_die" + number,
                ],
            }),
        ),
    )
    for number in [
        "0",
        "1",
    ]
]

# filegroup(
#     name = "die",
#     srcs = select({
#         "//filegroup:ipnext_enabled": [
#             ":tmp.txt",
#         ],
#         "//conditions:default": [
#         ],
#     }),
# )

fg_resources(
    name = "test_fg",
)

filegroup(
    name = "logs_fg",
    srcs = [":test_fg"],
    # output_group = "log_files",
)
