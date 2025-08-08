load("//genrule_example:rule.bzl", "foo")

genrule(
    name = "genrule_paths",
    srcs = ["script/script.sh"],
    outs = ["file.txt",],
    cmd = "./genrule_example/script/script.sh; read loc < <(realpath $@); echo 'Current dir:' $$(pwd); echo 'Output dir:' $$loc; mv file.txt $@",
)

foo(
    name = "foo_location",
)

genrule(
    name = "genrule_locations",
    srcs = [],
    tools = [
        ":foo_location"
    ],
    outs = ["locations.txt",],
    cmd = "echo $(locations foo_location) > $@",
)