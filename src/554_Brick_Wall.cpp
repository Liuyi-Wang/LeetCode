static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int count = 0;
        for (const auto &row:wall) {
            int s = 0;
            for (int i = 0; i < row.size()-1; ++i) {
                s += row[i];
                ++hash[s];
                count = max(count, hash[s]);
            }
        }
        return wall.size()-count;
    }
};
