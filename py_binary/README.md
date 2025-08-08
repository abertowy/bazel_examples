Usage:
python3 zuul_job_data.py --branch master --job ipnext-perf-build-and-upload --auth-token MY_AUTH_TOKEN --gh-token MY_GH_TOKEN --limit 1

Example request output:

[
    {
        '_id': 191214587,
        'uuid': '61622f6e2b0a44c3be021ca60fe26052',
        'job_name': 'ipnext-perf-build-and-upload',
        'result': 'SKIPPED',
        'held': False,
        'start_time': '2025-02-13T14:31:04',
        'end_time': '2025-02-13T14:31:04',
        'duration': 0.002248,
        'voting': True,
        'log_url': None,
        'nodeset': '',
        'error_detail': 'Skipped due to child_jobs return value in job ipnext-test-integration-select-jobs',
        'final': True,
        'artifacts': [],
        'provides': [],
        'ref': {
            'project': 'swh/ddad_ci_config',
            'branch': 'master',
            'change': 72218,
            'patchset': '2f396d3a4787e7e8038bdefad09859f2504fdbea',
            'ref': 'refs/pull/72218/head',
            'oldrev': None,
            'newrev': None,
            'ref_url': 'https://cc-github.bmwgroup.net/swh/ddad_ci_config/pull/72218'
        },
        'pipeline': 'manual-ipnext-test-integration',
        'event_id': 'd38a3e40-ea15-11ef-9e86-793919055967',
        'event_timestamp': '2025-02-13T14:21:34',
        'buildset': {'uuid': '01391fba305c4b478554844f5b3df1ff'}
    }
]

Example tool output:
{'swh/ddad_platform': 3, 'swh/ddad-ecu-ipnext': 1, 'swh/zuul-trusted-ddad': 1}
