#pragma once
#include <string>
#include <vector>
#include <algorithm>
//---------------------------------------------------------------------------------------------------
//Recursive Solution without data cache
//Helps you to understand the concept but its not the right solution because of the VERY LOW runtime
//---------------------------------------------------------------------------------------------------

//bool isMatch(std::string s, std::string p) {
//	bool isEmptyString = s.empty();			
//	bool isEmptyPattern = p.empty();
//	if (isEmptyString || isEmptyPattern)		//check if the text or the pattern is empty
//		return isEmptyString && (isEmptyPattern || (std::all_of(p.begin(), p.end(), [](const char c) {return c == '*'; })));		//return true if the text and the pattern are empty 
																																	//or if the text is empty and all the remaining char in the pattern are '*'	
																																	//because "****" can be equal two empty string
//	bool match = s[0] == p[0] || p[0] == '?';	//check if the fisrt chars are equal or it is an ?
//	if (p[0] == '*') {
//		return isMatch(s, p.substr(1, p.size()-1)) || isMatch(s.substr(1, s.size() - 1), p);	// this statement is divided to two parts
																								// we might need to remove the asterisk char (repeated recusively)
																								// we might need to remove a char from the text (repeated recusively)
																								// this statement will not be executed if in the second iteration (s[0]==p[0] || p[0]=='?')==true
//	}
//	else
//	{
//		return match && isMatch(s.substr(1, s.size() - 1),			//remove the 1st chars from both text & pattern
//								p.substr(1, p.size() - 1));
//	}
//}

//---------------------------------------------------------------------------------------------------
//Recursive Solution with data cache
//Refer to the fisrt implementation
//Better Efficency
//---------------------------------------------------------------------------------------------------

//class Solution {
//public:
//	bool isMatch(std::string s, std::string p) {
//		m_resultCache.resize(s.size() + 1, std::vector<Status>(p.size() + 1, Status::Uninitialized));
//		return doesTextAndPatternMatch(0, 0, s, p);
//	}
//private:
//	bool doesTextAndPatternMatch(const size_t i, const size_t j, std::string s, std::string p) {
//		if (m_resultCache[i][j] != Status::Uninitialized)
//		{
//			return m_resultCache[i][j]==Status::True;
//		}
//
//		bool finishString = i==s.size();
//		bool finishPattern = j==p.size();
//		
//		bool result;
//		
//		if (finishString || finishPattern)
//			result= finishString && (finishPattern || (std::all_of(p.begin()+j, p.end(), [](const char c) {return c == '*'; })));
//		else if (p[j] == '*') {
//			result= doesTextAndPatternMatch(i,j+1,s,p) || doesTextAndPatternMatch(i+1,j,s, p);
//		}
//		else
//		{
//			bool match = s[i] == p[j] || p[j] == '?';
//			result= match && doesTextAndPatternMatch(i+1, j+1, s, p);
//		}
//		m_resultCache[i][j] = Status(result);
//		return result;
//	}
//	enum class Status
//    {
//        Uninitialized = -1,
//        False = 0,
//        True = 1
//    };
//	std::vector<std::vector<Status>> m_resultCache;
//};

//---------------------------------------------------------------------------------------------------
//High Efficient Solution
//---------------------------------------------------------------------------------------------------

bool isMatch(std::string s, std::string p) {
	if (s.empty() && p.empty()) return true;
	else if(p.empty()) return false;

	size_t stringSize = s.size(), patternSize = p.size();
	size_t i = 0, j = 0;
	size_t previousAsterisk = -1, currChar = -1;	//last detected Asterisk, current char of the text (char position)

	while (i < stringSize)
	{
		if (j<patternSize && (s[i] == p[j] || p[j] == '?')) {
			++i;
			++j;
		}
		else if (p[j] == '*') {
			currChar = i; //get the current text char
			previousAsterisk = j; //get the '*' position
			++j;
		}
		else {
			if (previousAsterisk != -1) // if we detected a '*'
			{
				i = ++currChar;	// text char position will be increased, ie this char is part of the sequence matched by '*'
				j = previousAsterisk + 1;	
			}
			else {
				break;	//break because we have differences 
			}
		}
	}

	bool remainAsterisks = std::all_of(p.begin() + j, p.end(), [](const char c) {return c == '*'; });	//if all the remaining char in the pattern are '*' we can consider we reached the end of the pattern (because "*****" can be empty string)
	if (remainAsterisks) j = p.size();

	return i == s.size() && j == p.size();
}
