#pragma once
#include <vector>
#include <numeric>


namespace LEETCODE_1976 {
    class Solution {
    private:
        typedef std::vector<std::vector<std::pair<int,int>>> Graph;
        Graph m_graph;
        std::vector<bool> m_visited;
    public:
        int countPaths(int n, std::vector<std::vector<int>>& roads) 
        {
            m_graph = buildGraph(n, roads);
            m_visited  = std::vector<bool>(n, false);
            int minTime = std::numeric_limits<int>::max();
            int numberOfWays = 0;
            BFS(0, n - 1, 0, minTime, numberOfWays);
            return numberOfWays;
        }

    private:

        void BFS(const int src, const int dst, int currentTime, int & minTime, int & numberOfWays)
        {
            if (src == dst)
            {
                if (minTime > currentTime)
                {
                    minTime = currentTime;
                    numberOfWays = 1;
                }
                else if ( minTime == currentTime)
                {
                    ++numberOfWays;
                }
                return;
            }

            const std::vector<std::pair<int, int>>& neighbors = m_graph[src];
            m_visited[src] = true;
            for (const std::pair<int, int>& neighbor : neighbors)
            {
                const int neighborID = neighbor.first;
                const int duration = neighbor.second;
                if (!m_visited[neighborID])
                {
                    BFS(neighborID, dst, currentTime + duration, minTime, numberOfWays);
                }
            }
            m_visited[src] = false;
        }

        Graph buildGraph(const int n, const std::vector<std::vector<int>>& roads)
        {
            Graph graph(n);
            for (const std::vector<int>& road : roads)
            {
                const int intersection1 = road[0];
                const int intersection2 = road[1];
                const int time = road[2];

                graph[intersection1].push_back({ intersection2,time });
                graph[intersection2].push_back({ intersection1,time });
            }
            return graph;
        }
    };
}