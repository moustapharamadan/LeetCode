#include "../pch.h"
#include "../header/0739_Daily_Temperatures.hpp"

class DailyTemperatures : public ::testing::Test, public LEETCODE_0739::Solution {
};

TEST_F(DailyTemperatures, test1)
{
	std::vector<int>temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	std::vector<int> expectedOutput = { 1,1,4,2,1,1,0,0 };
	EXPECT_EQ(dailyTemperatures(temperatures), expectedOutput);
	EXPECT_EQ(dailyTemperatures2(temperatures), expectedOutput);
}

TEST_F(DailyTemperatures, test2)
{
	std::vector<int>temperatures = { 89, 62, 70, 58, 47, 47, 46, 76, 100, 70 };
	std::vector<int> expectedOutput = { 8,1,5,4,3,2,1,1,0,0 };
	EXPECT_EQ(dailyTemperatures(temperatures), expectedOutput);
	EXPECT_EQ(dailyTemperatures2(temperatures), expectedOutput);
}