import re

exclude_files = "(.*log|.*fileTable.[0-9]+|.*table.[0-9]+|.*info.[0-9]+|.*a2lfactory.exe)$"
file = "bazel-out/x64_windows-opt-exec-ST-dc6f6d140b09/bin/deployment/generic/cas/platform/tools/a2lfactory/a2lfactory"

print(re.search(exclude_files, file))