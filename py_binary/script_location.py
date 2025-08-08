import argparse
import os
from pathlib import Path
import subprocess


def define_script_location():
    parser = argparse.ArgumentParser("Download and extract backtrace from app")
    parser.add_argument(
        "-x",
        "--shell_script_path",
        type=str,
        help="Backtrace extraction script location",
        required=True,
    )
    args = parser.parse_args()

    print(args.shell_script_path)
    res = subprocess.run(
        [args.shell_script_path],
        capture_output=True,
        text=True,
    )
    print(res.stdout)

if __name__ == "__main__":
    define_script_location()
