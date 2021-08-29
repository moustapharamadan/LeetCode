#pragma once
#include <vector>

namespace LEETCODE_0983 {
    class Solution {
    public:
        int mincostTickets(const std::vector<int>& days, const std::vector<int>& costs) {
            if (days.empty())
                return 0;
            const int endDate = *(--days.end());
            const std::vector<int> validity = { 1,7,30 };

            constexpr int maxInt = std::numeric_limits<int>::max();
            m_cache= std::vector<int>(endDate+1, maxInt);
            m_cache[0] = 0;
            for (int i = 1; i <= endDate; ++i)
            {
                auto it = std::find(days.begin(), days.end(), i);
                if (it == days.end())
                {
                    m_cache[i] = m_cache[i - 1];
                }
                else {
                    for (int j = 0; j < costs.size(); ++j)
                    {
                        if (getCachedValue(i - validity[j]) != maxInt)
                        {
                            m_cache[i] = std::min(m_cache[i], getCachedValue(i - validity[j]) + costs[j]);
                        }
                    }
                }
            }
            return m_cache[endDate];
        }

    private:
        int getCachedValue(const int i)
        {
            if (0 <= i && i < m_cache.size())
                return m_cache[i];

            return 0;
        }
        std::vector<int> m_cache;
    };
}
