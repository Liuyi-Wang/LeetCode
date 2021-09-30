static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (0 == m) {
            return 0;
        }
        int n = grid[0].size();
        if (0 == n) {
            return 0;
        }
        vector<vector<int>> l = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> r = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> u = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> d = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if ('W' == grid[i][j-1]) {
                    continue;
                }
                if ('E' == grid[i][j-1]) {
                    l[i][j] = l[i][j-1]+1;
                } else {
                    l[i][j] = l[i][j-1];
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('W' == grid[i-1][j]) {
                    continue;
                }
                if ('E' == grid[i-1][j]) {
                    u[i][j] = u[i-1][j]+1;
                } else {
                    u[i][j] = u[i-1][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = n-2; j >= 0; --j) {
                if ('W' == grid[i][j+1]) {
                    continue;
                }
                if ('E' == grid[i][j+1]) {
                    r[i][j] = r[i][j+1]+1;
                } else {
                    r[i][j] = r[i][j+1];
                }
            }
        }
        for (int i = m-2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if ('W' == grid[i+1][j]) {
                    continue;
                }
                if ('E' == grid[i+1][j]) {
                    d[i][j] = d[i+1][j]+1;
                } else {
                    d[i][j] = d[i+1][j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('0' == grid[i][j]) {
                    result = max(result, l[i][j]+r[i][j]+u[i][j]+d[i][j]);
                }
            }
        }
        return result;
    }
};
