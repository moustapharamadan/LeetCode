#pragma once
#include <vector>
#include <string>

namespace LEETCODE_0022 {
    class Solution {
    public:
        std::vector<std::string> generateParenthesis(int n) 
        {
            std::string combination;
            DFS(combination, n, true);
            return m_result;
        }

    private:
        void DFS(std::string combination, const int n, bool openClose=true)
        {
            if (2 * n == combination.size())
            {
                m_result.push_back(combination);
                return;
            }

            openClose = combination.size() != n ? openClose : !openClose;
            combination += openClose ? m_openBracket : m_closeBracket;
            DFS(combination, n, openClose);
            DFS(combination, n, !openClose);
        }

        std::string m_openBracket = "(";
        std::string m_closeBracket = ")";
        std::vector<std::string> m_result;
    };
}