#include "../pch.h"
#include "../header/0300_Longest_Increasing_Subsequence.hpp"

class LongestIncreasingSubsequence : public ::testing::Test, public LEETCODE_0300::Solution {
};

TEST_F(LongestIncreasingSubsequence, Test) {
	std::vector<int> nums = { 10,9,2,5,3,7,101,18 };
	EXPECT_EQ(lengthOfLIS(nums), 4);
}