#include "../pch.h"
#include "../header/0345_Reverse_Vowels_of_a_String.hpp"

class ReverseVowelsInString : public ::testing::Test, public LEETCODE_0345::Solution {
};

TEST_F(ReverseVowelsInString, Leetcode)
{
	EXPECT_EQ(reverseVowels("Leetcode"), "Leotcede");
}
