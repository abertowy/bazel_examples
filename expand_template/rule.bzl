load("@bazel_skylib//lib:paths.bzl", "paths")

def _impl(ctx):
    output_file_name = paths.join("file.txt")
    output_file = ctx.actions.declare_file(output_file_name)

    ctx.actions.expand_template(
        template = ctx.file._template,
        output = output_file,
        substitutions = {
            "{FIRSTNAME}": ctx.attr.firstname,
            # "{FIRST.*?(}|$)": ctx.attr.firstname
        },
    )

    return [
        DefaultInfo(files = depset([output_file])),
    ]

hello_rule = rule(
    implementation = _impl,
    attrs = {
        "firstname": attr.string(mandatory = True),
        "_template": attr.label(
            default = ":file.template",
            allow_single_file = True,
        ),
    },
)