#include "../pch.h"
#include "../header/0713_Subarray_Product_Less_Than_K.hpp"

class NumSubarrayProductLessThanK : public ::testing::Test, public LEETCODE_0713::Solution {
};

TEST_F(NumSubarrayProductLessThanK, test1)
{
	std::vector<int> nums({ 10,5,2,6 });
	EXPECT_EQ(numSubarrayProductLessThanK(nums, 100) , 8);
}
