#include "../pch.h"
#include "../header/0151_Reverse_Words_in_a_String.hpp"

class ReverseWords : public ::testing::Test, public LEETCODE_0151::Solution {
};

TEST_F(ReverseWords, Test1)
{
	EXPECT_EQ(reverseWords("the sky is blue"), "blue is sky the");
}

