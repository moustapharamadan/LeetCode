#include "../pch.h"
#include "../header/0001_Two_Sum.hpp"

class TwoSum : public ::testing::Test, public LEETCODE_0001::Solution {
};

TEST_F(TwoSum, Nine)
{
	std::vector<int> nums = { 2, 7, 11, 15 };
	std::vector<int> indexes = { 1,0 };
	EXPECT_EQ(twoSum(nums, 9), indexes);
}
