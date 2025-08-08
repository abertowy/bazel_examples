import argparse
import requests
import numpy as np
import matplotlib.pyplot as plt


def func(pct, allvalues):
    absolute = int(pct / 100.*np.sum(allvalues))
    return "{:.1f}%\n({:d})".format(pct, absolute)


def request_job_data():
    parser = argparse.ArgumentParser(description="Get job data from zuul")

    parser.add_argument("--auth-token", required=True)
    parser.add_argument("--gh-token", required=True)
    parser.add_argument("--branch", required=True)
    parser.add_argument("--job", required=True)
    parser.add_argument("--limit", required=False)
    parser.add_argument("--project", required=False)

    args = parser.parse_args()

    if not args.limit:
        limit = 5
    else:
        limit = args.limit

    standard_url = f"https://zuul.cc.bmwgroup.net/zuul/api/tenant/ddad/builds?limit={limit}&skip=1700&branch={args.branch}&job_name={args.job}"
    headers = {"Authorization": f"Bearer {args.auth_token}"}

    result = requests.get(standard_url, headers=headers).json()

    repos = []
    runs = {}
    prs = {}
    for item in result:
        project = item["ref"]["project"]
        if project not in repos:
            repos.append(project)
            runs.update({project: 1})
            prs.update({project: [item["ref"]["change"]]})
        else:
            runs.update({project: runs[project]+1})
            prs.update({project: prs[project] + [item["ref"]["change"]]})

    print(f"Job '{args.job}' executions per repo:")
    print(runs)

    # labeled_prs = {}
    job_data = []
    for project in prs:
        print(f"Processing '{project}' PRs ...")
        job_data.append({"project": project, "pull_requests": {"total": len(prs[project]), "unique": len(set(prs[project]))}})

    # for project in prs:
    #     print(f"Processing '{project}' PRs ...")
    #     # labeled_prs.update({project: {}})
    #     job_data.append({})
    #     ipnext_relevant = job_data[-1]
    #     prs.update({project: set(prs[project])})
    #     ipnext_relevant.update({"project": project})
    #     ipnext_relevant.update({"pull_requests": {"total": len(prs[project]), "ipnext-perf-relevant": 0}})
    #     for issue in prs[project]:
    #         gh_url = f"https://cc-github.bmwgroup.net/api/v3/repos/{project}/issues/{issue}/labels"
    #         gh_headers = {"Authorization": f"Bearer {args.gh_token}"}
    #         result = requests.get(gh_url, headers=gh_headers).json()
    #         labels = []
    #         for item in result:
    #             try:
    #                 labels.append(item["name"])
    #             except:
    #                 continue
    #         # labeled_prs[project].update({issue: labels})
    #         if "ipnext-perf-relevant" in labels:
    #             ipnext_relevant["pull_requests"].update({"ipnext-perf-relevant": ipnext_relevant["pull_requests"]["ipnext-perf-relevant"]+1})

    # # print(f"Job '{args.job}' executions on unique PRs per repo:")
    # # print(labeled_prs)
    # print(f"Job '{args.job}' executions on 'ipnext-perf-relevant' PRs per repo:")
    # print(job_data)

    # Creating plot
    fig, ax = plt.subplots()
    wedges, texts, autotexts = ax.pie(list(runs.values()), autopct=lambda pct: func(pct, list(runs.values())), labels=runs.keys())
    plt.setp(autotexts, size=8, weight="bold")
    ax.set_title(f"Job '{args.job}' executions per repo")
    plt.show()

    projects = len(job_data)
    repos_data = []
    total_prs = []
    ipnext_prs = []
    for item in job_data:
        repos_data.append(item["project"])
        total_prs.append(item["pull_requests"]["total"])
        ipnext_prs.append(item["pull_requests"]["unique"])
    # for item in job_data:
    #     repos_data.append(item["project"])
    #     total_prs.append(item["pull_requests"]["total"])
    #     ipnext_prs.append(item["pull_requests"]["ipnext-perf-relevant"])

    fig_1, ax_1 = plt.subplots()
    index = np.arange(projects)
    bar_width = 0.35
    opacity = 0.8

    rects1 = plt.barh(index, total_prs, bar_width, alpha=opacity, label='total prs')
    rects2 = plt.barh(index + bar_width, ipnext_prs, bar_width, alpha=opacity, label='unique prs')
    # rects2 = plt.barh(index + bar_width, ipnext_prs, bar_width, alpha=opacity, label='ipnext-perf-relevant')

    # plt.title(f"Job '{args.job}' executions on 'ipnext-perf-relevant' PRs per repo")
    plt.title(f"Job '{args.job}' executions on unique PRs per repo")
    plt.yticks(index + bar_width/2, repos_data)
    plt.legend()

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    request_job_data()