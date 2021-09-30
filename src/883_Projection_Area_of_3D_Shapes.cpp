static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0); 
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 != grid[i][j]) {
                    ++result;
                }
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for (auto r:row) {
            result += r;
        }
        for (auto c:col) {
            result += c;
        }
        return result;
    }
};
