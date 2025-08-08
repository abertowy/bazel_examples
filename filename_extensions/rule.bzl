load("@bazel_skylib//lib:paths.bzl", "paths")

def _impl(ctx):
    print("APP NAME:", ctx.attr.app)
    print("IDS:", ctx.attr.ids)
    output_file = ctx.actions.declare_file(ctx.attr.filename)

    ctx.actions.write(
        output = output_file,
        content = "Hello world!",
    )

    return [
        DefaultInfo(files = depset([output_file])),
    ]

extension_rule = rule(
    implementation = _impl,
    attrs = {
        "filename": attr.string(
            doc = "Content that will be added to the output file",
            default = "filename.txt",
            mandatory = False,
        ),
        "app": attr.string(
            doc = "APP name from logistics map",
            default = "APP_0_NA",
            mandatory = False,
        ),
        "ids": attr.string(
            doc = "IDs list from logistics map",
            default = "NA",
            mandatory = False,
        ),
        "extension": attr.string(
            doc = "Content that will be added to the output file",
            default = "production",
            mandatory = False,
        ),
    },
)