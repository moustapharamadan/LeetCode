#include "../pch.h"
#include "../header/0191_Number_of_1_Bits.hpp"

TEST(hammingWeight, Test1)
{
    LEETCODE_0191::Solution s;
    EXPECT_EQ(3, s.hammingWeight(00000000000000000000000000001011));
}