#include "../pch.h"
#include "../header/1514_Path_With_Maximum_Probability.hpp"


class MaxProbabilityPath : public ::testing::Test, public LEETCODE_1514::Solution {
};

TEST_F(MaxProbabilityPath, ThreeEdgesConnected) {
	std::vector<std::vector<int>>edges = { {0, 1},{1, 2},{0, 2} };
	std::vector<double>succProb = { 0.5, 0.5, 0.2 };
	int start = 0, end = 2, n = 3;
	EXPECT_EQ(maxProbability(n, edges, succProb, start, end), 0.25);
}
TEST_F(MaxProbabilityPath, ThreeEdges_TwoConnected) {
	std::vector<std::vector<int>>edges = { {0, 1} };
	std::vector<double>succProb = { 0.5 };
	int start = 0, end = 2, n = 3;
	EXPECT_EQ(maxProbability(n, edges, succProb, start, end), 0.);
}
TEST_F(MaxProbabilityPath, FiveEdges) {
	std::vector<std::vector<int>>edges = { {2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2} };
	std::vector<double>succProb = { 0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77 };
	int start = 0, end = 3, n = 5;
	EXPECT_EQ(maxProbability(n, edges, succProb, start, end), 0.16);
}