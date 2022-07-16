#include "../pch.h"
#include "../header/0084_Largest_Rectangle_in_Histogram.hpp"

class LargestRectangleArea : public ::testing::Test, public LEETCODE_0084::Solution {
};

TEST_F(LargestRectangleArea, test1)
{
	std::vector<int> heights{ 2,1,5,6,2,3 };

	EXPECT_EQ(largestRectangleArea(heights), 10);
}
