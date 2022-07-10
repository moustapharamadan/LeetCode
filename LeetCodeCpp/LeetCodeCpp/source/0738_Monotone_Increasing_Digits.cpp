#include "../pch.h"
#include "../header/0738_Monotone_Increasing_Digits.hpp"

class MonotoneIncreasingDigits : public ::testing::Test, public LEETCODE_0738::Solution {
};

TEST_F(MonotoneIncreasingDigits, test1)
{
	EXPECT_EQ(monotoneIncreasingDigits(10), 9);
}