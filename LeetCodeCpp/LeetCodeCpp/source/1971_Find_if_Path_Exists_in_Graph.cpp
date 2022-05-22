#include "../pch.h"
#include "../header/1971_Find_if_Path_Exists_in_Graph.hpp"

class FindIfPathExistsInGraph : public ::testing::Test, public LEETCODE_1971::Solution {
};

TEST_F(FindIfPathExistsInGraph, test1)
{
	std::vector<std::vector<int>> edges{ {0,1}, {1,2}, {2,0} };
	EXPECT_TRUE(validPath(3, edges, 0, 2));
}

TEST_F(FindIfPathExistsInGraph, test2)
{
	std::vector<std::vector<int>> edges{ {0,1}, {1,2}, {2,0} };
	EXPECT_TRUE(validPath(3, edges, 0, 0));
}
