#pragma once

#include <vector>
#include <queue>
#include <limits>

namespace LEETCODE_0310 {
    class Solution {
    public:
        typedef std::vector<std::vector<int>> Graph;

        std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) 
        {    
            Graph graph = buildGraph(n, edges);
            std::queue<int> leaves;
            for (int i = 0; i < graph.size(); ++i)
            {
                if (1 >= graph[i].size())
                {
                    leaves.push(i);
                }
            }

            int remainingNode = n;
            while (remainingNode > 2)
            {
                remainingNode -= leaves.size();
                std::queue<int> newLeaves;
                while (!leaves.empty())
                {
                    int leaf = leaves.front(); leaves.pop();
                    int neighbor = graph[leaf][0];

                    graph[leaf].clear();
                    graph[neighbor].erase(std::find(graph[neighbor].begin(), graph[neighbor].end(), leaf));

                    if (1 == graph[neighbor].size())
                    {
                        newLeaves.push(neighbor);
                    }
                }
                leaves = newLeaves;
            }

            std::vector<int> result;
            while (!leaves.empty())
            {
                result.push_back(leaves.front());
                leaves.pop();
            }
            return result;
        }

        Graph buildGraph(const int numCourses, const std::vector<std::vector<int>>& edges)
        {
            Graph graph(numCourses);
            for (int i = 0; i < edges.size(); ++i)
            {
                const int node1 = edges[i][0];
                const int node2 = edges[i][1];
                graph[node1].push_back(node2);
                graph[node2].push_back(node1);
            }
            return graph;
        }
    };
}
