load("@bazel_skylib//lib:paths.bzl", "paths")

def _impl(ctx):
    common_dir = paths.join("empty_dir_01")
    test_output = ctx.actions.declare_directory(common_dir)

    test_data_files = []
    for file in ctx.attr.test_data.files.to_list():
        test_data_files.append(file)
    test_data_dir = test_data_files[-1].dirname

    args = ctx.actions.args()

    args.add("--metrics-artifacts", test_data_dir)
    args.add("--output-dir", test_output.path)
    args.add("--metrics-file", test_data_dir)
    args.add("--branch", ctx.attr.branch)

    ctx.actions.run(
        outputs = [test_output],
        inputs = test_data_files,
        arguments = [args],
        progress_message = "Do smth",
        executable = ctx.executable._glanz_tool,
    )

    return [
        DefaultInfo(files = depset([test_output])),
    ]

glanz_rule = rule(
    implementation = _impl,
    attrs = {
        "branch": attr.string(
            doc = "Branch",
            mandatory = False,
        ),
        "test_data": attr.label(
            doc = "Test data dir",
            mandatory = True,
        ),
        "_glanz_tool": attr.label(
            doc = "Glanz tool",
            default = Label("//dir_output:glanz"),
            executable = True,
            cfg = "exec",
        ),
    },
)
