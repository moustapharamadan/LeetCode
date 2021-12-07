#include "../pch.h"
#include "../header/0279_Perfect_Squares.hpp"

class PerfectSquares : public ::testing::Test, public LEETCODE_0279::Solution {
};

TEST_F(PerfectSquares, test1)
{
	EXPECT_EQ(numSquares(12), 3);
}

TEST_F(PerfectSquares, test2)
{
	EXPECT_EQ(numSquares(13), 2);
}
