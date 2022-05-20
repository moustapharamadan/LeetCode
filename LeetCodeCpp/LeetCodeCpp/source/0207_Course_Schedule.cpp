#include "../pch.h"
#include "../header/0207_Course_Schedule.hpp"

class CourseScheduleI : public ::testing::Test, public LEETCODE_0207::Solution {
};

TEST_F(CourseScheduleI, acyclic)
{
	std::vector<std::vector<int>> prerequisites = { {1,0}, {2,0}, {3,1}, {3,2} };
	EXPECT_TRUE(canFinish(4, prerequisites));
	EXPECT_TRUE(canFinish2(4, prerequisites));
}

TEST_F(CourseScheduleI, cyclic)
{
	std::vector<std::vector<int>> prerequisites = { {1,0}, {0,1} };
	EXPECT_FALSE(canFinish(2, prerequisites));
	EXPECT_FALSE(canFinish2(2, prerequisites));
}

TEST_F(CourseScheduleI, acyclic2)
{
	std::vector<std::vector<int>> prerequisites = { {1,0} };
	EXPECT_TRUE(canFinish(2, prerequisites));
	EXPECT_TRUE(canFinish2(2, prerequisites));
}

TEST_F(CourseScheduleI, empty)
{
	std::vector<std::vector<int>> prerequisites = { };
	EXPECT_TRUE(canFinish(2, prerequisites));
	EXPECT_TRUE(canFinish2(2, prerequisites));
}