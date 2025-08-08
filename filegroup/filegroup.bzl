LogInfo = provider("Provides logfile", fields = {"files": "path to the log"})

def _fg_resources_impl(ctx):
    output_file = ctx.actions.declare_file("dummy.txt")
    log_file = ctx.actions.declare_file("logfile.txt")
    ctx.actions.write(
        content = "AAAAA",
        output = output_file,
    )
    ctx.actions.write(
        content = "BBBBB",
        output = log_file,
    )
    return [
        DefaultInfo(files = depset([output_file])),
        LogInfo(files = depset([log_file])),
        OutputGroupInfo(
            log_files = depset([log_file]),
        ),
    ]

fg_resources = rule(
    implementation = _fg_resources_impl,
)
