#pragma once
#include <string>
#include <map>

namespace LEETCODE_0012 {
    class Solution {
    public:
        std::string intToRoman(int num) {
            const static std::map<int, std::string, std::greater<int>> romanNumerals{
                {1000,"M"},
                {900,"CM"},
                {500,"D"},
                {400,"CD"},
                {100,"C"},
                {90,"XC"},
                {50,"L"},
                {40,"XL"},
                {10,"X"}, 
                {9,"IX"},
                {5,"V"},
                {4,"IV"},
                {1,"I"},
            };

            std::string result = "";
            for (const std::pair< int, std::string>& number : romanNumerals) {
                const int repeat = num / number.first;
                for (int i = 0; i < repeat; ++i)
                    result += number.second;
                num = num % number.first;
            }
            return result;
        }
    };
}
