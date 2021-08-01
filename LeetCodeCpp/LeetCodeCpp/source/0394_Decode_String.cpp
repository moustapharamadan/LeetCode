#include "../pch.h"
#include "../header/0394_Decode_String.hpp"

class DecodeString : public ::testing::Test, public LEETCODE_0394::Solution {
};

TEST_F(DecodeString, abcabcabcababababc) {
	EXPECT_EQ(decodeString("3[abc]4[ab]c"), "abcabcabcababababc");
}

TEST_F(DecodeString, aaabaaab) {
	EXPECT_EQ(decodeString("2[3[a]b]"), "aaabaaab");
}

TEST_F(DecodeString, ManyConcatenation) {
	EXPECT_EQ(decodeString("3[[abc]4[zk]]6[bmw]"), "abczkzkzkzkabczkzkzkzkabczkzkzkzkbmwbmwbmwbmwbmwbmw");
}

TEST_F(DecodeString, abcabccdcdcdef) {
	EXPECT_EQ(decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
}

TEST_F(DecodeString, abccdcdcdxyz) {
	EXPECT_EQ(decodeString("abc3[cd]xyz"), "abccdcdcdxyz");
}

TEST_F(DecodeString, leetcode) {
	EXPECT_EQ(decodeString("100[leetcode]"), "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode");
}