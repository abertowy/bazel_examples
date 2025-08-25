#include <vector>
#include <queue>
#include <utility>

std::vector<int> dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>& graph) {
    std::vector<int> distances(graph.size(), INT_MAX);
    distances[start] = 0;
    using pii = std::pair<int, int>; // Pair for distance and node
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        for (const auto& [neighbor, weight] : graph[node]) {
            if (dist + weight < distances[neighbor]) {
                distances[neighbor] = dist + weight;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }
    return distances;
}