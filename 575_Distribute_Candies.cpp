static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (auto c:candies) {
            s.insert(c);
        }
        return min(candies.size()/2, s.size());
    }
};
