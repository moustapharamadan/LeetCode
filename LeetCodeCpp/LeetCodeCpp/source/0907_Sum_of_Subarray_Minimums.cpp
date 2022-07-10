#include "../pch.h"
#include "../header/0907_Sum_of_Subarray_Minimums.hpp"

class SumSubarrayMins : public ::testing::Test, public LEETCODE_0907::Solution {
};


TEST_F(SumSubarrayMins, Test1)
{
    std::vector<int> arr({ 3,1,2,4 });
    EXPECT_EQ(17, sumSubarrayMins(arr));
}


TEST_F(SumSubarrayMins, Test2)
{
    std::vector<int> arr({ 71,55,82,55 });
    EXPECT_EQ(593, sumSubarrayMins(arr));
}