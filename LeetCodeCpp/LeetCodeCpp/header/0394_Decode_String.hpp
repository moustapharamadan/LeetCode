#pragma once
#include <string>
#include <stack>

namespace LEETCODE_0394 {
    class Solution {
    public:
        std::string decodeString(std::string input) {
            std::stack<int> coefficients;
            std::stack<std::string> words;
            words.push("");

            int number = 0;
            for (int i = 0; i < input.size(); ++i)
            {
                if ('0' <= input[i] && input[i] <= '9')
                {
                    number = number * 10 + std::stoi(std::string(1, input[i]));
                }
                else if ('[' == input[i])
                {
                    if (number)
                    {
                        coefficients.push(number);
                        number = 0;
                    }
                    else {
                        coefficients.push(1);
                    }
                    words.push("");
                }
                else if (']' == input[i])
                {
                    std::string word = words.top();
                    words.pop();
                    int coeff = coefficients.top();
                    coefficients.pop();
                    std::string output = words.top();
                    words.pop();
                    for (int k = 0; k < coeff; ++k)
                    {
                        output += word;
                    }
                    words.push(output);
                }
                else {
                    words.top().push_back(input[i]);
                }
            }

            return words.top();
        }
    };
}