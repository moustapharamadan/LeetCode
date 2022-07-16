#include "../pch.h"
#include "../header/0901_Online_Stock_Span.hpp"

class StockSpanner : public ::testing::Test, public LEETCODE_0901::StockSpanner {
};

TEST_F(StockSpanner, test1)
{
	EXPECT_EQ(next(100), 1);
	EXPECT_EQ(next(80), 1); 
	EXPECT_EQ(next(60), 1); 
	EXPECT_EQ(next(70), 2); 
	EXPECT_EQ(next(60), 1); 
	EXPECT_EQ(next(75), 4);
	EXPECT_EQ(next(85), 6);
}


TEST_F(StockSpanner, test2)
{
	EXPECT_EQ(next(28), 1);
	EXPECT_EQ(next(14), 1);
	EXPECT_EQ(next(28), 3);
	EXPECT_EQ(next(35), 4);
	EXPECT_EQ(next(46), 5);
	EXPECT_EQ(next(53), 6);
	EXPECT_EQ(next(66), 7);
	EXPECT_EQ(next(80), 8);
	EXPECT_EQ(next(87), 9);
	EXPECT_EQ(next(88), 10);
}