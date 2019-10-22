static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (2 == cost.size()) {
            return min(cost[0], cost[1]);
        }
        int c1 = cost[0], c2 = cost[1];
        int result;
        for (int i = 2; i < cost.size(); ++i) {
            result = min(c1, c2) + cost[i];
            c1 = c2;
            c2 = result;
        }
        return min(result, c1);
    }
};
