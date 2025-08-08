import argparse
import requests
import json


def get_fixture_data():
    parser = argparse.ArgumentParser(description="Get pr data from")

    parser.add_argument("--gh-token", required=True)
    parser.add_argument("--branch", required=False)
    parser.add_argument("--pull-request", required=False)
    parser.add_argument("--project", required=False)

    args = parser.parse_args()

    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/{project}/issues/{issue}/labels"
    # PR
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/{args.project}/pulls/{args.pull_request}"
    # Labels
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/{args.project}/issues/{args.pull_request}/labels"
    gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/swh/ci-testing-ground/issues/1473/labels"
    # Repo
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/{args.project}"
    # ORG
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/orgs/swh"
    # USer
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/user"
    # Team id
    # gh_url = f"https://cc-github.bmwgroup.net/api/v3/orgs/swh/teams/ipnext-sysabs-testing-ctw"
    gh_headers = {"Authorization": f"Bearer {args.gh_token}"}
    result = requests.get(gh_url, headers=gh_headers).json()
    print(result)

    # with open("/tmp/coredumps/0001.json", "w") as f:
    #     json.dump(result, f, indent=4)


if __name__ == "__main__":
    get_fixture_data()