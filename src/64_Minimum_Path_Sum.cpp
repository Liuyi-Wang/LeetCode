static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            grid[0][j] += grid[0][j-1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};
