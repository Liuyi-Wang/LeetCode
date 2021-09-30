static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m*n);
        if (0 == k) {
            return grid;
        }
        cout << k << endl;
        int r = (k-1)/n;
        int c = (k-1)%n;
        queue<int> q;
        for (int i = n-c-1; i < n; ++i) {
            q.push(grid[m-r-1][i]);
        }
        for (int i = m-r; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.push(grid[i][j]);
            }
        }
        for (int i = m*n-k-1; i >= 0; --i) {
            int j = i+k;
            grid[j/n][j%n] = grid[i/n][i%n];
        }
        for (int i = 0; i < k; ++i) {
            grid[i/n][i%n] = q.front();
            q.pop();
        }
        return grid;
    }
};
