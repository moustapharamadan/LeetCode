#pragma once
#include <vector>
#include <numeric>
#include <array>

namespace LEETCODE_0473
{
    class Solution {
    public:
        bool makesquare(std::vector<int>& matchsticks) {
            if (matchsticks.empty())
                return false;
        
            const int perimeter = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
            m_possibleSideLength = perimeter / 4;
            if (0 != perimeter % 4)
                return false;
            std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
            return DFS(matchsticks, 0);
        }

    private:
        bool DFS(std::vector<int>& matchsticks, const int index)
        {
            if (index == matchsticks.size())
                return m_sidesLength[0] == m_sidesLength[1] && m_sidesLength[1] == m_sidesLength[2] && m_sidesLength[2] == m_sidesLength[3];

            const int matchstick = matchsticks[index];
            for (int i = 0; i < m_sidesLength.size(); ++i)
            {
                if (m_sidesLength[i] + matchstick <= m_possibleSideLength)
                {
                    m_sidesLength[i] += matchstick;
                    if (DFS(matchsticks, index + 1))
                        return true;
                    m_sidesLength[i] -= matchstick;
                }
            }
            return false;
        }

        int m_possibleSideLength;
        std::array<int, 4> m_sidesLength = { 0,0,0,0 };
    };
}