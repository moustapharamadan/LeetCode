#include "../pch.h"
#include "../header/0523_Continuous_Subarray_Sum.hpp"

class CheckSubarraySum : public ::testing::Test, public LEETCODE_0523::Solution {
};

TEST_F(CheckSubarraySum, test1)
{
	std::vector<int> nums({ 23,2,4,6,7 });
	EXPECT_TRUE(checkSubarraySum(nums, 6));
}

TEST_F(CheckSubarraySum, test2)
{
	std::vector<int> nums({ 23,2,4,6,6 });
	EXPECT_TRUE(checkSubarraySum(nums, 7));
}

TEST_F(CheckSubarraySum, test3)
{
	std::vector<int> nums({ 5,0,0,0 });
	EXPECT_TRUE(checkSubarraySum(nums, 3));
}