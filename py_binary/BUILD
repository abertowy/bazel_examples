py_binary(
    name = "script_location",
    srcs = [
        "script_location.py",
    ],
    args = [
        "-x=$(location script.sh)",
    ],
    data = [
        ":script.sh",
    ],
    main = "script_location.py",
)