#include "../pch.h"
#include "../header/0473_Matchsticks_to_Square.hpp"

class MatchsticksToSquare : public ::testing::Test, public LEETCODE_0473::Solution {
public:
	std::vector<int> m_matchsticks;
};

TEST_F(MatchsticksToSquare, Square2cm)
{
	m_matchsticks = { 1,1,2,2,2 };
	EXPECT_TRUE(makesquare(m_matchsticks));
}

TEST_F(MatchsticksToSquare, notSquare)
{
	m_matchsticks = { 3,3,3,3,4 };
	EXPECT_FALSE(makesquare(m_matchsticks));
}
