#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

namespace LEETCODE_0151 {
    class Solution {
    public:
        std::string reverseWords(const std::string& s) {
            std::vector<std::string> sentence;
            std::stringstream ss(s);
            for (std::string word; ss >> word;)
                sentence.push_back(word);

            std::string result;
            for (int i=sentence.size()-1;i>=0;--i)
            {
                result += sentence[i];
                if (i != 0)
                    result += " ";
            }
            return result;
        }
    };
}
#pragma once
