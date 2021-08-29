#pragma once
#include <vector>
#include <map>
#include <string>

namespace LEETCODE_0139 {
    class Solution {
    public:
        bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
            return recursion(s, wordDict, 0);
        }

        bool recursion(const std::string& s, const std::vector<std::string>& wordDict, const int index)
        {
            if (s.size() == index)
                return true;
            
            auto it = m_dp.find(index);
            if (it != m_dp.end())
                return it->second;

            bool result = false;
            for (const std::string& word : wordDict)
            {
                std::string sub = s.substr(index, s.size());
                if (0 == sub.rfind(word, 0))
                {
                    m_dp[index] = recursion(s, wordDict, index + word.size());
                    result |= m_dp[index];
                }
            }
            return result;
        }

    private:
        std::map<int,bool> m_dp;
    };
}
#pragma once
