import os
import argparse

def create_dir():
    parser = argparse.ArgumentParser(description="DO SMTH")

    parser.add_argument("--metrics-artifacts", required=True)
    parser.add_argument("--output-dir", required=True)
    parser.add_argument("--metrics-file", required=True)
    parser.add_argument("--branch", required=True)

    args = parser.parse_args()

    if not os.path.exists(args.output_dir):
        os.mkdir(args.output_dir)

    os.chdir(args.output_dir)
    filename = ".dummy"
    with open(filename, "w+") as file:
        file.write("test")

if __name__ == "__main__":
    create_dir()
