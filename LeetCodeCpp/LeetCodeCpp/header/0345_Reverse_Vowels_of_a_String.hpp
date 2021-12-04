#pragma once
#include <string>
#include <stack>

namespace LEETCODE_0345 {
    class Solution {
    public:
        std::string reverseVowels(const std::string& s) {
            std::stack<char> vowels;
            for (const char& c : s)
            {
                char lowerCase = tolower(c);
                if ('a' == lowerCase || 'e' == lowerCase || 'i' == lowerCase || 'o' == lowerCase || 'u' == lowerCase)
                    vowels.push(c);
            }

            if (vowels.empty())
                return s;

            std::string result;
            for (const char& c : s)
            {
                char lowerCase = tolower(c);
                if ('a' == lowerCase || 'e' == lowerCase || 'i' == lowerCase || 'o' == lowerCase || 'u' == lowerCase)
                {
                    result += vowels.top();
                    vowels.pop();
                }
                else
                {
                    result += c;
                }
            }
            return result;
        }
    };
}
