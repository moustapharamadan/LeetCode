#include <string>
#include <unordered_map>

int firstUniqChar(std::string s) {
	std::unordered_map<char, int> charContainer;
	for (int i = 0; i < s.size();++i) {
		charContainer[s[i]] += 1;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (charContainer[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}
