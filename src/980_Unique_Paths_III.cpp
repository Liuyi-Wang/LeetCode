static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(vector<vector<int>>& grid, int si, int sj, int count) {
        if (si == d_i && sj == d_j && count == d_count) {
            ++d_result;
            return;
        }
        if (si == d_i && sj == d_j) {
            return;
        }
        grid[si][sj] = -2;
        for (int x = 0; x < d_di.size(); ++x) {
            int I = si+d_di[x];
            int J = sj+d_dj[x];
            if (I >= 0 && I < grid.size() && J >= 0 && J < grid[0].size() && grid[I][J] >= 0) {
                solve(grid, I, J, count+1);
            }
        }
        grid[si][sj] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        d_result = 0;
        d_count = 2;
        d_di = {-1, 0, 0, 1};
        d_dj = {0, -1, 1, 0};
        int m = grid.size(), n = grid[0].size();
        int si, sj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == grid[i][j]) {
                    ++d_count;
                } else if (1 == grid[i][j]) {
                    si = i;
                    sj = j;
                } else if (2 == grid[i][j]) {
                    d_i = i;
                    d_j = j;
                }
            }
        }
        solve(grid, si, sj, 1);
        return d_result;
    }
    
private:
    int d_result;
    int d_count;
    int d_i;
    int d_j;
    vector<int> d_di;
    vector<int> d_dj;
};
