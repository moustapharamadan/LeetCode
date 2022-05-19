#pragma once

#include <vector>
#include <map>
#include <queue>
#include <numeric>


namespace LEETCODE_0210 {
    class Solution {
    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
            if (prerequisites.empty())
            {
                std::vector<int> typologicalOrder(numCourses);
                std::iota(typologicalOrder.begin(), typologicalOrder.end(), 0);
                return typologicalOrder;
            }

            std::map<int, std::vector<int>> adjacentNodes;
            std::vector<int> nodesInDegree(numCourses, 0);
            for (const std::vector<int>& pair : prerequisites)
            {
                const int src = pair[1];
                const int dest = pair[0];
                adjacentNodes[src].push_back(dest);
                ++nodesInDegree[dest];
            }
            
            std::queue<int> nodesQueue;
            for (int i = 0; i < nodesInDegree.size(); ++i)
            {
                if (0 == nodesInDegree[i])
                {
                    nodesQueue.push(i);
                }
            }

            
            std::vector<int> typologicalOrder;
            while (!nodesQueue.empty())
            {
                int nodeID = nodesQueue.front(); nodesQueue.pop();
                typologicalOrder.push_back(nodeID);
                for (const int adjNodeID : adjacentNodes[nodeID])
                {
                    --nodesInDegree[adjNodeID];
                    if (0 == nodesInDegree[adjNodeID])
                    {
                        nodesQueue.push(adjNodeID);
                    }
                }
            }
            return typologicalOrder.size() == numCourses ? typologicalOrder : std::vector<int>();
        }

    };
}
