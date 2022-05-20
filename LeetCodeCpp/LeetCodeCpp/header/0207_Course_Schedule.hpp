#pragma once

#include <vector>
#include <map>
#include <queue>
#include <numeric>


namespace LEETCODE_0207 {
    class Solution {
    private:
        typedef std::vector<std::vector<int>> Graph;

    public:

        bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
        {
            auto [graph, inDegree] = buildGraphAndInDegree(numCourses, prerequisites);
            
            for (int i = 0; i < graph.size(); ++i)
            {
                int j = 0;
                for (; j < numCourses; ++j)
                {
                    if (!inDegree[j])
                    {
                        break;
                    }
                }

                if (j == numCourses)
                {
                    return false;
                }

                inDegree[j] = -1; //to mean it was visited so it wont be considered anymore

                for (int index : graph[j])
                {
                    inDegree[index]--;
                }
            }

            return true;
        }

        bool canFinish2(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            auto [graph, inDegree] = buildGraphAndInDegree(numCourses, prerequisites);

            std::queue<int> q;
            int remainingNbCourses = numCourses;
            for (int i = 0; i < numCourses; ++i)
            {
                if (!inDegree[i])
                {
                    q.push(i);
                    --remainingNbCourses;
                }
            }

            while (!q.empty())
            {
                int index = q.front(); q.pop();
                inDegree[index] = -1;
                for (int neighbor : graph[index])
                {
                    --inDegree[neighbor];
                    if (!inDegree[neighbor])
                    {
                        q.push(neighbor);
                        --remainingNbCourses;
                    }
                }
            }

            return 0 == remainingNbCourses;
        }
        
        std::pair<Graph, std::vector<int>> buildGraphAndInDegree(const int numCourses, const std::vector<std::vector<int>>& prerequisites)
        {
            Graph graph(numCourses);
            std::vector<int> inDegree(numCourses, 0);
            for (int i = 0; i < prerequisites.size(); ++i)
            {
                const int src = prerequisites[i][1];
                const int dst = prerequisites[i][0];
                graph[src].push_back(dst);
                inDegree[dst]++;
            }
            return { graph, inDegree };
        }

    };
}
