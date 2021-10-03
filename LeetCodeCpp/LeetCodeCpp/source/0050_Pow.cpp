#include "../pch.h"
#include "../header/0050_Pow.hpp"

class Power : public ::testing::Test, public LEETCODE_0050::Solution {
};

TEST_F(Power, infinity)
{
	EXPECT_EQ(myPow(1.,-2147483648), 1);
}
