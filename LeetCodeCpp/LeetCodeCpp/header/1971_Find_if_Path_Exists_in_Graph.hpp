#pragma once
#include <vector>
#include <queue>

namespace LEETCODE_1971 {
    class Solution {
    private:
        typedef std::vector<std::vector<int>> Graph;
    public:
        bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) 
        {
            Graph graph = buildGraph(n, edges);
            //return BFS(source, destination, graph);

            std::vector<bool> isVisited(graph.size(), false);
            return DFS(source, destination, graph, isVisited);
        }

    private:

        bool BFS(const int source, const int destination, const Graph& graph)
        {
            if (source == destination)
            {
                return true;
            }
            std::vector<bool> isVisited(graph.size(), false);
            std::queue<int> q;
            q.push(source);

            while (!q.empty())
            {
                const int node = q.front(); q.pop();
                isVisited[node] = true;
                const std::vector<int>& neighbors = graph[node];
                for (const int neighbor : neighbors)
                {
                    if (!isVisited[neighbor])
                    {
                        if (neighbor == destination)
                        {
                            return true;
                        }
                        q.push(neighbor);
                    }
                }
            }

            return false;
        }

        bool DFS(const int source, const int destination, const Graph& graph, std::vector<bool>& isVisited)
        {
            if (source == destination)
            {
                return true;
            }

            isVisited[source] = true;
            const std::vector<int>& neighbors = graph[source];
            for (const int neighbor : neighbors)
            {
                if (!isVisited[neighbor])
                {
                    if (DFS(neighbor, destination, graph, isVisited))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        Graph buildGraph(const int n, const std::vector<std::vector<int>>& edges)
        {
            Graph graph(n);
            for (const std::vector<int>& edge : edges)
            {
                const int node1 = edge[0];
                const int node2 = edge[1];

                graph[node1].push_back(node2);
                graph[node2].push_back(node1);
            }

            return graph;
        }
    };
}