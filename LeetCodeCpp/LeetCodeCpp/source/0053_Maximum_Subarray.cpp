#include "../pch.h"
#include "../header/0053_Maximum_Subarray.hpp"

class MaximumSubarray : public ::testing::Test, public LEETCODE_0053::Solution {
};

TEST_F(MaximumSubarray, test)
{
	std::vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	EXPECT_EQ(maxSubArray(nums), 6);
}
