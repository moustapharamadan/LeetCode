#include "../pch.h"
#include "../header/0042_Trapping_Rain_Water.hpp"

class TrappingRainWater : public ::testing::Test, public LEETCODE_0042::Solution {
};

TEST_F(TrappingRainWater, Test) {
	std::vector<int> height = { 1,3,2,4,1,3,1,4,5,2,2,1,4,2,2 };
	EXPECT_EQ(trap(height), 15);
}
