from pathlib import Path

def str_test():
    projects = ["swh/orion","swh/ddad_ci_config"]
    root_path = Path("/home/zuul/src/cc-github.bmwgroup.net/swh/ddad")
    root_url = "git@cc-github.bmwgroup.net:swh/ddad.git"
    submodules = []

    paths = [Path(root_path / p) for p in projects]
    print(paths)

    for project in projects:
        if project not in [d.get("project") for d in submodules]:
            short_name = project.split("/")[-1]
            submodules.append(
                {
                    "path": root_path.resolve().parent / short_name,
                    "url": root_url.replace("ddad", short_name),
                    "project": project,
                }
            )
    print(submodules)


if __name__ == "__main__":
    str_test()