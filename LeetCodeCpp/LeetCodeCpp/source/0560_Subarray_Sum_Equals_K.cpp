#include "../pch.h"
#include "../header/0560_Subarray_Sum_Equals_K.hpp"

class SubarraySum : public ::testing::Test, public LEETCODE_0560::Solution {
};

TEST_F(SubarraySum, test1)
{
	std::vector<int> nums({ 1,1,1 });
	EXPECT_EQ(subarraySum(nums, 2), 2);
}

TEST_F(SubarraySum, test2)
{
	std::vector<int> nums({ 1,2,3 });
	EXPECT_EQ(subarraySum(nums, 3), 2);
}

TEST_F(SubarraySum, test3)
{
	std::vector<int> nums({ 1,2,1,2,1 });
	EXPECT_EQ(subarraySum(nums, 3), 4);
}
