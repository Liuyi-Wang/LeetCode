static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (0 == grid[i][j]) {
                    continue;
                }
                result += 4;
                if (i-1 >= 0 && 1 == grid[i-1][j]) {
                    --result;
                }
                if (j-1 >= 0 && 1 == grid[i][j-1]) {
                    --result;
                }
                if (i+1 < grid.size() && 1 == grid[i+1][j]) {
                    --result;
                }
                if (j+1 < grid[i].size() && 1 == grid[i][j+1]) {
                    --result;
                }
            }
        }
        return result;
    }
};
