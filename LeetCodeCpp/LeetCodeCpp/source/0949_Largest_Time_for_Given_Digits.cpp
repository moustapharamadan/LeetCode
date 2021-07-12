#include "../pch.h"
#include <algorithm>
#include <numeric>

#include "../header/0949_Largest_Time_for_Given_Digits.hpp"

class LargestTimeFromDigits : public ::testing::Test, public LEETCODE_0949::Solution {
};

TEST_F(LargestTimeFromDigits, validTest1)
{
    std::vector<int> arr = { 1,2,3,4 };
    EXPECT_EQ("23:41", largestTimeFromDigits(arr));
}

TEST_F(LargestTimeFromDigits, validTest2)
{
    std::vector<int> arr = { 0,0,0,2 };
    EXPECT_EQ("20:00", largestTimeFromDigits(arr));
}

TEST_F(LargestTimeFromDigits, invalid)
{
    std::vector<int> arr = { 5,5,5,5 };
    EXPECT_EQ("", largestTimeFromDigits(arr));
}

TEST_F(LargestTimeFromDigits, invalid2)
{
    std::vector<int> arr = { 4, 2, 4, 4 };
    EXPECT_EQ("", largestTimeFromDigits(arr));
}


TEST_F(LargestTimeFromDigits, validEdgeCase2)
{
    std::vector<int> arr = { 2, 0, 6,0 };
    EXPECT_EQ("20:06", largestTimeFromDigits(arr));
}

