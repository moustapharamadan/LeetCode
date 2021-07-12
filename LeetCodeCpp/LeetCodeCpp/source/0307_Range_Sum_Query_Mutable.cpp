#include "../pch.h"
#include "../header/0307_Range_Sum_Query_Mutable.hpp"

TEST(RangeSumQuery, sqrtDecomposition)
{
    std::vector<int> arr = { 0,9,5,7,3 };
    LEETCODE_0307::sqrtDecomposition::NumArray numArray(arr);

    EXPECT_EQ(3, numArray.sumRange(4,4));
    EXPECT_EQ(15, numArray.sumRange(2,4));
    EXPECT_EQ(7, numArray.sumRange(3,3));
    numArray.update(4, 5);
    numArray.update(1, 7);
    numArray.update(0, 8);
    EXPECT_EQ(12, numArray.sumRange(1, 2));
    numArray.update(1, 9);
    EXPECT_EQ(5, numArray.sumRange(4, 4));
    numArray.update(3, 4);
}

TEST(RangeSumQuery, segmentTree)
{
    std::vector<int> arr = { 0,9,5,7,3 };
    LEETCODE_0307::segmentTree::NumArray numArray(arr);

    EXPECT_EQ(3, numArray.sumRange(4, 4));
    EXPECT_EQ(15, numArray.sumRange(2, 4));
    EXPECT_EQ(7, numArray.sumRange(3, 3));
    numArray.update(4, 5);
    numArray.update(1, 7);
    numArray.update(0, 8);
    EXPECT_EQ(12, numArray.sumRange(1, 2));
    numArray.update(1, 9);
    EXPECT_EQ(5, numArray.sumRange(4, 4));
    numArray.update(3, 4);
}

TEST(RangeSumQuery, segmentTree2)
{
    std::vector<int> arr = { 7, 2, 7, 2, 0 };
    LEETCODE_0307::segmentTree::NumArray numArray(arr);
    
    numArray.update(4, 6);
    numArray.update(0, 2);
    numArray.update(0, 9);

    EXPECT_EQ(6, numArray.sumRange(4, 4));
    numArray.update(3, 8);
    EXPECT_EQ(32, numArray.sumRange(0, 4));
    numArray.update(4, 1);
    EXPECT_EQ(26, numArray.sumRange(0, 3));
    EXPECT_EQ(27, numArray.sumRange(0, 4));
}
