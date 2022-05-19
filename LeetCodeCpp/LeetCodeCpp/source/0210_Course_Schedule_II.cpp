#include "../pch.h"
#include "../header/0210_Course_Schedule_II.hpp"

class CourseSchedule : public ::testing::Test, public LEETCODE_0210::Solution {
};

TEST_F(CourseSchedule, test1)
{
	std::vector<std::vector<int>> prerequisites = { {1,0}, {2,0}, {3,1}, {3,2} };
	std::vector<int> result = findOrder(4, prerequisites);
	EXPECT_EQ(result, std::vector<int>({ 0,1,2,3 }));
}

TEST_F(CourseSchedule, test2)
{
	std::vector<std::vector<int>> prerequisites = { {1,0}, {1, 2}, {0,1} };
	std::vector<int> result = findOrder(3, prerequisites);
	EXPECT_EQ(result, std::vector<int>());
}
