#pragma once
#include <string>
#include <vector>

//without kleene star (Recursion Solution)
//bool isMatch(std::string s, std::string p) {
//	if (p.empty())
//		return s.empty();
//	bool match = !s.empty() && (p[0] == s[0] || p[0] == '.');
//	return match && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
//}

//with kleene star (Recursion Solution)
//bool isMatch(std::string s, std::string p) {
//	if (p.empty())
//		return s.empty();
//	bool match = !s.empty() && (p[0] == s[0] || p[0] == '.');
//	if (p.size() > 1 && p[1] == '*') {
//		return isMatch(s, p.substr(2, p.size() - 1)) || (match && isMatch(s.substr(1, s.size() - 1), p));
//	}
//	else
//	{
//		return match && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
//	}
//}


//Dynamic Programming Solution
//class Solution {
//public:
//    bool isMatch(std::string s, std::string p) {
//        m_resultCache.resize(s.size()+1, std::vector<Status>(p.size()+1, Status::Uninitialized));
//        return patternMatch(0, 0, s, p);
//    }
//private:
//    enum class Status
//    {
//        Uninitialized = -1,
//        False = 0,
//        True = 1
//    };
//    bool patternMatch(const size_t i, const size_t j, std::string& s, std::string& p)
//    {
//        if (m_resultCache[i][j]!=Status::Uninitialized) {
//            return m_resultCache[i][j] == Status::True;
//        }
//        bool result;
//        if (j == p.size()) {
//            result = i == s.size();
//        }
//        else {
//            bool firstMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
//            if (j + 1 < p.size() && p[j + 1] == '*') {
//                result = patternMatch(i, j + 2, s, p) || (firstMatch && patternMatch(i + 1, j, s, p));
//            }
//            else {
//                result = firstMatch && patternMatch(i + 1, j + 1, s, p);
//            }
//        }
//        m_resultCache[i][j] = Status(result);
//        return result;
//    }
//
//    std::vector<std::vector<Status>> m_resultCache;
//};


//Bottom-Up Variation
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::vector < std::vector<bool>> dp(s.size()+1,std::vector<bool>(p.size()+1,false));
        dp[s.length()][p.length()] = true;

        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool first_match = (i < s.size() && (p[j]== s[i] || p[j] == '.'));
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                }
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
