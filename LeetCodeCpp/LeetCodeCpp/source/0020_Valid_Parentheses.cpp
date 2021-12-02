#include "../pch.h"
#include "../header/0020_Valid_Parentheses.hpp"


class ValidParentheses : public ::testing::Test, public LEETCODE_0020::Solution {
};

TEST_F(ValidParentheses, Empty)
{
	EXPECT_TRUE(isValid(""));
}

TEST_F(ValidParentheses, NotClosing)
{
	EXPECT_FALSE(isValid("["));
}

TEST_F(ValidParentheses, startClosing)
{
	EXPECT_FALSE(isValid("]"));
}

TEST_F(ValidParentheses, False)
{
	EXPECT_FALSE(isValid("([)]"));
}

TEST_F(ValidParentheses, True)
{
	EXPECT_TRUE(isValid("{[]}"));
}
