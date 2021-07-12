#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Change
{
	long coin2 = 0;
	long bill5 = 0;
	long bill10 = 0;
};

long sum(const Change& c)
{
	return c.bill10 * 10 + c.bill5 * 5 + c.coin2 * 2;
}

void print(const Change& c)
{
	std::cout << "Coin(s) 2€: " << c.coin2 << "\n";
	std::cout << "Coin(s) 5€: " << c.bill5 << "\n";
	std::cout << "Coin(s) 10€: " << c.bill10 << "\n";
}

bool optimalChange(long amount, Change& c)
{
	if (amount >= 5 && amount % 2 == 1)
	{
		c.bill5 = 1;
		amount -= 5;
	}

	c.bill10 = amount / 10;
	amount %= 10;
	c.coin2 = amount / 2;
	amount %= 2;

	return 0 == amount;
}