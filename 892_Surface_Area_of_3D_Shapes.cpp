static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 != grid[i][j]) {
                    ++result;
                }
            }
        }
        result *= 2;
        for (int i = 0; i < m; ++i) {
            int last = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > last) {
                    result += grid[i][j]-last;
                }
                last = grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            int last = 0;
            for (int j = n-1; j >= 0; --j) {
                if (grid[i][j] > last) {
                    result += grid[i][j]-last;
                }
                last = grid[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            int last = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] > last) {
                    result += grid[i][j]-last;
                }
                last = grid[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            int last = 0;
            for (int i = m-1; i >= 0; --i) {
                if (grid[i][j] > last) {
                    result += grid[i][j]-last;
                }
                last = grid[i][j];
            }
        }
        return result;
    }
};
