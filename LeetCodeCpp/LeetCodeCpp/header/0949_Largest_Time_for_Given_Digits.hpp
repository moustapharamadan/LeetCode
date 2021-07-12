#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include <sstream>

namespace LEETCODE_0949
{
	class Solution {
	public:
		std::string largestTimeFromDigits(std::vector<int>& arr) {
			int maxTime = -1;
			std::sort(arr.begin(), arr.end());
			do {
				int hours = arr[0] * 10 + arr[1];
				int minutes = arr[2] * 10 + arr[3];
				if (hours < 24 && minutes < 60)
				{
					maxTime = std::max(maxTime, hours * 60 + minutes);
				}
			} while (std::next_permutation(arr.begin(), arr.end()));
			if (-1 == maxTime)
				return "";

			std::stringstream ss;
			ss << std::setfill('0') << std::setw(2) << maxTime / 60 << ":" << std::setw(2) << maxTime % 60;
			return ss.str();
		}
	};
}

//string largestTimeFromDigits(vector<int>& arr) {
//	int maxTime = -1;
//	std::sort(arr.begin(), arr.end());
//	do {
//		int hour = arr[0] * 10 + arr[1];
//		int minute = arr[2] * 10 + arr[3];
//		if (hour < 24 && minute < 60) {
//			int newTime = hour * 60 + minute;
//			maxTime = std::max(newTime, maxTime);
//		}
//	}while(next_permutation(arr.begin(), arr.end()));
//	if (-1 == maxTime)
//		return "";
//
//	std::ostringstream ss;
//	ss << std::setw(2) << std::setfill('0') << maxTime / 60
//		<< ":" << std::setw(2) << std::setfill('0') << maxTime % 60;
//	return ss.str();
//
//}
