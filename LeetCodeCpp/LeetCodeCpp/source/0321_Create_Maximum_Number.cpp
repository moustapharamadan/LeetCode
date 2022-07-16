#include "../pch.h"
#include "../header/0321_Create_Maximum_Number.hpp"

class CreateMaximumNumber : public ::testing::Test, public LEETCODE_0739::Solution {
};

TEST_F(CreateMaximumNumber, test1)
{
	std::vector<int> nums1{ 3, 4, 6, 5 }, nums2 { 9, 1, 2, 5, 8, 3 };
	std::vector<int> expected{ 9, 8, 6, 5, 3 };

	EXPECT_EQ(maxNumber(nums1, nums2, 5), expected);
}

TEST_F(CreateMaximumNumber, test2)
{
	std::vector<int> nums1{ 6, 7 }, nums2{ 6, 0, 4 };
	std::vector<int> expected{ 6,7,6,0,4 };

	EXPECT_EQ(maxNumber(nums1, nums2, 5), expected);
}

TEST_F(CreateMaximumNumber, test3)
{
	std::vector<int> nums1{ 6, 7, 5 }, nums2{ 4, 8, 1 };
	std::vector<int> expected{ 8,7,5 };

	EXPECT_EQ(maxNumber(nums1, nums2, 3), expected);
}

//TEST_F(CreateMaximumNumber, test4)
//{
//	std::vector<int> nums1{ 8, 0, 4, 4, 1, 7, 3, 6, 5, 9, 3, 6, 6, 0, 2, 5, 1, 7, 7, 7, 8, 7, 1, 4, 4, 5, 4, 8, 7, 6, 2, 2, 9, 4, 7, 5, 6, 2, 2, 8, 4, 6, 0, 4, 7, 8, 9, 1, 7, 0 }, 
//		nums2{ 6, 9, 8, 1, 1, 5, 7, 3, 1, 3, 3, 4, 9, 2, 8, 0, 6, 9, 3, 3, 7, 8, 3, 4, 2, 4, 7, 4, 5, 7, 7, 2, 5, 6, 3, 6, 7, 0, 3, 5, 3, 2, 8, 1, 6, 6, 1, 0, 8, 4 };
//	std::vector<int> expected{ 9,9,9,9,9,8,7,5,6,3,4,2,4,7,4,5,7,7,2,5,6,3,6,7,2,2,8,4,6,0,4,7,8,9,1,7,0,3,5,3,2,8,1,6,6,1,0,8,4,0 };
//
//	EXPECT_EQ(maxNumber(nums1, nums2, 50), expected);
//}