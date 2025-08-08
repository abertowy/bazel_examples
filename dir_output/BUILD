
load("//dir_output:rule.bzl", "glanz_rule")

py_binary(
    name = "glanz",
    srcs = ["make_glanz.py"],
    main = "make_glanz.py",
)

glanz_rule(
    name = "glanz_empty_dir",
    branch = "master",
    test_data = ":test_data",
    visibility = ["//visibility:public"],
)

py_test(
    name = "test_dir_output",
    testonly = True,
    srcs = ["test.py"],
    args = ["$(location :glanz_empty_dir)"],
    data = [":glanz_empty_dir"],
    main = "test.py",
)

filegroup(
    name = "test_data",
    srcs = glob(
        [
            "test_data/**",
        ],
        allow_empty = True,
    ),
    visibility = ["//visibility:public"],
)
