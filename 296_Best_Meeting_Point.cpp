static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x, y;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (1 == grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int result = 0;
        for (int i = 0; i < x.size()/2; ++i) {
            result += x[x.size()-1-i]-x[i];
            result += y[y.size()-1-i]-y[i];
        }
        return result;
    }
};
