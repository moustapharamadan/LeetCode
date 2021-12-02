#include "../pch.h"
#include "../header/0012_Integer_to_Roman.hpp"

class IntegerToRoman : public ::testing::Test, public LEETCODE_0012::Solution {
};

TEST_F(IntegerToRoman, oneThousandNineHundredAndNinetyFourth)
{
	EXPECT_EQ(intToRoman(1994), "MCMXCIV");
}

TEST_F(IntegerToRoman, fiftyEight)
{
	EXPECT_EQ(intToRoman(58), "LVIII");
}
