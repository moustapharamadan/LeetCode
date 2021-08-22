#include "../pch.h"
#include "../header/0011_Container_With_Most_Water.hpp"

class ContainerWithMostWater : public ::testing::Test, public LEETCODE_0011::Solution {
};

TEST_F(ContainerWithMostWater, Three)
{
	std::vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	EXPECT_EQ(maxArea(height), 49);
}
