#include "../pch.h"
#include "../header/1253_Reconstruct_a_2_Row_Binary_Matrix.hpp"

TEST(reconstructMatrix, Test1)
{
    LEETCODE_1253::Solution s;
    std::vector<std::vector<int>> result = s.reconstructMatrix(2, 1, { 1,1,1 });
    std::vector<std::vector<int>> expectedResult = { {1, 0, 1},{0, 1, 0} };
    bool isEqual = result == expectedResult;
    
    expectedResult = { {0,1,1},{1,0,0 } };
    isEqual |= result == expectedResult;

    expectedResult = { {1,1,0},{0,0,1 } };
    isEqual |= result == expectedResult;

    EXPECT_TRUE(isEqual);
}

TEST(reconstructMatrix, Test2)
{
    LEETCODE_1253::Solution s;
    std::vector<std::vector<int>> result = s.reconstructMatrix(5, 5, { 2, 1, 2, 0, 1, 0, 1, 2, 0, 1 });
    std::vector<std::vector<int>> expectedResult = { { 1, 1, 1, 0, 1, 0, 0, 1, 0, 0 },{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 1 } };
    bool isEqual = result == expectedResult;

    EXPECT_TRUE(isEqual);
}