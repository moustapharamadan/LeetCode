#include <vector>
#include <algorithm>

//Apply the greedy algorithm to maximize profit
//The profit is to choose the city where to send a person
//we have to sort in descending order the cost vector according to the price difference between the two cities.
//we must choose the lowest costs if no city reaches the maximum N
//By applying this approach, we initially choose the cheapest cities where the difference is huge (reduction of high costs)
//and at the end we chose the remaining cities even if they are not the cheapest ones because there is no huge difference

int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
	std::sort(costs.begin(), costs.end(), [](const std::vector<int>& v1, const std::vector<int>& v2) {return abs(v1[1] - v1[0])>abs(v2[1] - v2[0]) ;  });
	int a = 0, b = 0;
	int n = costs.size()/2;
	int sum = 0;
	for (int j = 0; j < 2 * n; ++j) {
		if (b == n || (costs[j][0] <= costs[j][1] && a < n)) {
			sum += costs[j][0];
			a++;
		}
		else {
			sum += costs[j][1];
			b++;
		}
	}
	return sum;
}
