load("@bazel_skylib//lib:paths.bzl", "paths")

def _stack_resources_impl(ctx):
    args = ctx.actions.args()
    output_file = ctx.actions.declare_file("stack_measurement.txt")
    src_path = ctx.file.src_context.path
    print(src_path)

    ctx.actions.write(
        content = src_path,
        output = output_file,
    )
    return [
        DefaultInfo(files = depset([output_file])),
        OutputGroupInfo(output_file = depset([output_file])),
    ]

gen_stack_resources = rule(
    implementation = _stack_resources_impl,
    attrs = {
        "src_context": attr.label(
            mandatory = True,
            allow_single_file = True,
            doc = """input the stack / task / context configuration file in order to associate the requirements with the proper stacks""",
        ),
    },
)