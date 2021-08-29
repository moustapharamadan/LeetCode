#include "../pch.h"
#include "../header/0983_Minimum_Cost_For_Tickets.hpp"

class MincostTickets : public ::testing::Test, public LEETCODE_0983::Solution {
};

TEST_F(MincostTickets, Nine)
{
	std::vector<int> days = { 1,4,6,7,8,20 };
	std::vector<int> costs = { 2,7,15 };
	EXPECT_EQ(mincostTickets(days, costs), 11);
}
TEST_F(MincostTickets, Six)
{
	std::vector<int> days = { 1,4,6,7,8,20 };
	std::vector<int> costs = { 7, 2, 15 };
	EXPECT_EQ(mincostTickets(days, costs), 6);
}
