#include<vector>
#include<map>
#include<stack>

//int majorityElement(std::vector<int>& nums) {
//	std::map<int, int> frequency;
//	for (const int n : nums) {
//		frequency[n] += 1;
//	}
//	for (const int n : nums) {
//		if (frequency[n] > nums.size() / 2.) return n;
//	}
//	return 0;
//}

//int majorityElement(std::vector<int>& nums) {
//    std::stack<int> s;
//    for (int n : nums) {
//        if (!s.empty() && s.top() != n) {
//            s.pop();
//        }
//        else {
//            s.push(n);
//        }
//    }
//    return s.top();
//}

int majorityElement(std::vector<int>& nums) {
    std::pair<int, int> result(0,0); //first= num, second= count (frequency of num)
    for (int n : nums) {
        if (result.second == 0) {
            result.first = n;
        }
        result.second += (result.first == n) ? 1 : -1;
    }
    return result.first;
}
