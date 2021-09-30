static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        stack<pair<int, int>> s;
        grid[i][j] = -1;
        s.push(pair<int, int>(i, j));
        while (!s.empty()) {
            i = s.top().first;
            j = s.top().second;
            s.pop();
            for (int k = 0; k < d_i.size(); ++k) {
                int I = i + d_i[k];
                int J = j + d_j[k];
                if (I >= 0 && J >= 0 && I < grid.size() && J < grid[0].size() && '1' == grid[I][J]) {
                    grid[I][J] = -1;
                    s.push(pair<int, int>(I, J));
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        d_i = {-1, 0, 0, 1};
        d_j = {0, -1, 1, 0};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0 ; j < grid[0].size(); ++j) {
                if ('1' == grid[i][j]) {
                    ++result;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
private:
    vector<int> d_i;
    vector<int> d_j;
};
