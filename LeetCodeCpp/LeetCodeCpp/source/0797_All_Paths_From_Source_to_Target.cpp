#include "../pch.h"
#include "../header/0797_All_Paths_From_Source_to_Target.hpp"

class AllPathsFromSourceToTarget : public ::testing::Test, public LEETCODE_0797::Solution {
};

TEST_F(AllPathsFromSourceToTarget, test1)
{
	std::vector<std::vector<int>> graph = { {1, 2}, {3}, {3}, {} };
	std::vector<std::vector<int>> expected = { {0, 1, 3}, {0, 2, 3} };
	EXPECT_EQ(allPathsSourceTarget(graph), expected);
}