#include "../pch.h"
#include "../header/0054_Spiral_Matrix.hpp"

class SpiralMatrix : public ::testing::Test, public LEETCODE_0054::Solution {
};

TEST_F(SpiralMatrix, test1)
{
	std::vector<std::vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	std::vector<int> result = spiralOrder(matrix);
	std::vector<int> expected = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
	EXPECT_EQ(result, expected);
}