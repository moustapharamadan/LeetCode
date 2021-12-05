#include "../pch.h"
#include "../header/0752_Open_the_Lock.hpp"

class OpenTheLock : public ::testing::Test, public LEETCODE_0752::Solution {
};

TEST_F(OpenTheLock, test1)
{
	std::vector<std::string> deadends = { "0201", "0101", "0102", "1212", "2002" };
	EXPECT_EQ(openLock(deadends, "0202"), 6);
}
