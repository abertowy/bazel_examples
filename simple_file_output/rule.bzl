load("@bazel_skylib//lib:paths.bzl", "paths")

def _impl(ctx):
    output_file_name = paths.join("file.txt")
    output_file = ctx.actions.declare_file(output_file_name)

    ctx.actions.write(
        output = output_file,
        content = ctx.attr.content,
    )

    return [
        DefaultInfo(files = depset([output_file])),
    ]

simple_rule = rule(
    implementation = _impl,
    attrs = {
        "content": attr.string(
            doc = "Content that will be added to the output file",
            default = "Lorem Ipsum",
            mandatory = False,
        ),
    },
)