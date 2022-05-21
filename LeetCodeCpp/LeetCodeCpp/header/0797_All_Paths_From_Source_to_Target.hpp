#pragma once

#include <vector>

namespace LEETCODE_0797 {
    class Solution {
    public:
        std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
            std::vector<std::vector<int>> result;
            BFS(0, graph.size() - 1, graph, {}, result);
            return result;
        }

        void BFS(const int src, const int dst, const std::vector<std::vector<int>>& graph, std::vector<int> path, std::vector<std::vector<int>>& result)
        {
            path.push_back(src);
            if (src == dst)
            {
                result.push_back(path);
                return;
            }

            const std::vector<int>& neighbors = graph[src];
            for (int neighbor : neighbors)
            {
                BFS(neighbor, dst, graph, path, result);
            }
        }
    };
}
