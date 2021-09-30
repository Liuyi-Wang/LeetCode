static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        stack<pair<int, int>> s;
        int area = 1;
        grid[i][j] = -1;
        s.push(pair<int, int>(i, j));
        while (!s.empty()) {
            i = s.top().first;
            j = s.top().second;
            s.pop();
            for (int k = 0; k < d_i.size(); ++k) {
                int I = i + d_i[k];
                int J = j + d_j[k];
                if (I >= 0 && J >= 0 && I < grid.size() && J < grid[0].size() && grid[I][J] == 1) {
                    ++area;
                    grid[I][J] = -1;
                    s.push(pair<int, int>(I, J));
                }
            }
        }
        d_result = max(d_result, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        d_i = {-1, 0, 0, 1};
        d_j = {0, -1, 1, 0};
        int m = grid.size(), n = grid[0].size();
        d_result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (1 == grid[i][j]) {
                    dfs(grid, i, j);    
                }
            }
        }
        return d_result;
    }
private:
    int d_result;
    vector<int> d_i;
    vector<int> d_j;
};
