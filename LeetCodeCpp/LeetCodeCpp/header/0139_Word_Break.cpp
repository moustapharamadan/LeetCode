#include "../pch.h"
#include "../header/0139_Word_Break.hpp"

class WordBreak : public ::testing::Test, public LEETCODE_0139::Solution {
};

TEST_F(WordBreak, test1)
{
	std::string s = "leetcode";
	std::vector<std::string> wordDict = { "leet", "code" };
	EXPECT_TRUE(wordBreak(s,wordDict));
}

TEST_F(WordBreak, test2)
{
	std::string s = "catsandog";
	std::vector<std::string> wordDict = { "cat", "and", "dog", "cats", "an", "sand" };
	EXPECT_TRUE(wordBreak(s, wordDict));
}

TEST_F(WordBreak, TimeLimit)
{
	std::string s = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
	std::vector<std::string> wordDict = { "abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c", "cbdbcad", "cdbab", "db", "abbcdbd", "bcb", "bbdab", "aa", "bcadb", "bacbcb", "ca", "dbdabdb", "ccd", "acbb", "bdc", "acbccd", "d", "cccdcda", "dcbd", "cbccacd", "ac", "cca", "aaddc", "dccac", "ccdc", "bbbbcda", "ba", "adbcadb", "dca", "abd", "bdbb", "ddadbad", "badb", "ab", "aaaaa", "acba", "abbb" };
	EXPECT_TRUE(wordBreak(s, wordDict));
}
