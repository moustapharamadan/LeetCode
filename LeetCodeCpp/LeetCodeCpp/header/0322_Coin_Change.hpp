#pragma once
#include <vector>
#include <limits>

namespace LEETCODE_0322 {
    class Solution {
    public:
        int coinChange(const std::vector<int>& coins, const int amount) 
        {
            if (amount < 0)
                return -1;
            constexpr int maxInt = std::numeric_limits<int>::max();
            std::vector<int> cache = std::vector<int>(amount + 1, maxInt);
            cache[0] = 0;
            for (int i = 1; i <= amount; ++i)
            {
                for (int coin : coins)
                {
                    if (i - coin >= 0 && cache[i - coin] != maxInt)
                        cache[i] = std::min(cache[i], cache[i - coin] + 1);
                }
            }
            return cache[amount]== maxInt?-1: cache[amount];
        }
    };
}
