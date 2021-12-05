#pragma once
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

namespace LEETCODE_0752 {
    class Solution {
    public:
        int openLock(const std::vector<std::string>& deadends, const std::string& target)
        {
            if ("0000" == target)
                return 0;
            std::queue<std::string>q;
            q.push("0000");

            std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
            auto insertedItem = visited.insert("0000");
            if (!insertedItem.second)
                return -1;

            bool found = false;
            int count = 0;
            while (!q.empty() && !found)
            {
                const int size = q.size();
                ++count;
                for (int i = 0; i < size && !found; ++i)
                {
                    found = generateCombination(q.front(), target, deadends, visited, q);
                    q.pop();
                }
            }
            return found ? count : -1;
        }

    private:
        bool generateCombination(const std::string& currentLock,
            const std::string& target,
            const std::vector<std::string>& deadends,
            std::unordered_set<std::string>& visited,
            std::queue<std::string>& q)
        {
            for (int i = 0; i < currentLock.size(); ++i)
            {
                const int number = currentLock[i] - '0';
                const int increment = (number + 1) % 10;
                const int decrement = (number - 1 + 10) % 10;

                std::string result = currentLock;
                result[i] = '0' + increment;
                if (result == target)
                    return true;
                auto insertedReesult = visited.insert(result);
                if (insertedReesult.second)
                    q.push(result);

                result[i] = '0' + decrement;
                if (result == target)
                    return true;
                insertedReesult = visited.insert(result);
                if (insertedReesult.second)
                    q.push(result);
            }
            return false;
        }
    };
}
