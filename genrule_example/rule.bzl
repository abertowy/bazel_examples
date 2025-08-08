def _impl(ctx):

  output_1 = ctx.actions.declare_file(ctx.label.name + "_1.sh")
  output_2 = ctx.actions.declare_file(ctx.label.name + "_2.sh")

  cmds = ["mkdir -p {dirname}; touch {dirname}/sample.file; ".format(dirname = output_1.path), ]

  ctx.actions.write(output = output_1, content = "\n".join(["#!/bin/sh"] + cmds) + "\n", is_executable = True)
  ctx.actions.write(output = output_2, content = "\n".join(["#!/bin/sh"] + cmds) + "\n", is_executable = True)

  return [DefaultInfo(files = depset([ output_1, output_2, ]),)]

foo = rule(
  implementation = _impl,
)