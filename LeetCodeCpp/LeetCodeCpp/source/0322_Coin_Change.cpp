#include "../pch.h"
#include "../header/0322_Coin_Change.hpp"

class CoinChange : public ::testing::Test, public LEETCODE_0322::Solution {
};

TEST_F(CoinChange, Test1)
{
	std::vector<int> coins = { 1,2,5 };
	int amount = 11;
	EXPECT_EQ(coinChange(coins, amount), 3);
}

TEST_F(CoinChange, Test2)
{
	std::vector<int> coins = { 2 };
	int amount = 3;
	EXPECT_EQ(coinChange(coins, amount), -1);
}

TEST_F(CoinChange, Test3)
{
	std::vector<int> coins = { 186,419,83,408 };
	int amount = 6249;
	EXPECT_EQ(coinChange(coins, amount), 20);
}
