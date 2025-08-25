#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> mergeIntervals(std::vector<std::pair<int, int>>& intervals) {
    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<int, int>> merged;

    auto current = intervals[0];
    for (const auto& interval : intervals) {
        if (interval.first <= current.second) {
            current.second = std::max(current.second, interval.second);
        } else {
            merged.push_back(current);
            current = interval;
        }
    }
    merged.push_back(current);

    return merged;
}