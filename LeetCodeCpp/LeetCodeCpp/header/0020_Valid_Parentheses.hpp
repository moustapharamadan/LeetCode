#pragma once
#include <string>
#include <stack>

namespace LEETCODE_0020 {
    class Solution {
    public:
        bool isValid(const std::string& s) {
            std::stack<char> parentheses;
            for (const char& c : s)
            {
                if ('(' == c || '{' == c || '[' == c)
                {
                    parentheses.push(c);
                }
                else {
                    if (parentheses.empty())
                        return false;

                    if (')' == c)
                    {
                        if (parentheses.top() != '(')
                            return false;
                    }
                    else if ('}' == c)
                    {
                        if (parentheses.top() != '{')
                            return false;
                    }
                    else if (']' == c)
                    {
                        if (parentheses.top() != '[')
                            return false;
                    }
                    parentheses.pop();
                }
            }

            return parentheses.empty();
        }
    };
}
