load("//custom_rule:custom_rule.bzl", "gen_stack_resources")

filegroup(
    name = "test_files",
    srcs = ["test.txt", "test.json"],
    # srcs = ["test.txt"],
)

gen_stack_resources(
    name = "stack",
    src_context = ":test_files",
    visibility = ["//visibility:public"],
)