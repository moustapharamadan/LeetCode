#include "../pch.h"
#include "../header/optimalChange.hpp"


TEST(OptimalChange, Three)
{
	Change change;
	srand(time(nullptr));
	EXPECT_FALSE(optimalChange(3, change));
	EXPECT_EQ(2, sum(change));
}

TEST(OptimalChange, RandomValues)
{
	Change change;
	srand(time(nullptr));
	long amount = rand() % 999999999 + 5;
	EXPECT_TRUE(optimalChange(amount, change));
	EXPECT_EQ(amount, sum(change));
}
