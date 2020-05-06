static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(int i, int j, int x, int y, string &s, vector<vector<int>> &grid) {
        if (0 == grid[i][j]) {
            return;
        }
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int I = i+d_i[k];
            int J = j+d_j[k];
            if (I < 0 || J < 0 || I >= m || J >= n || 0 == grid[I][J]) {
                continue;
            }
            s += (to_string(x+d_i[k])+"_"+to_string(y+d_j[k])+"_");
            solve(I, J, x+d_i[k], y+d_j[k], s, grid);
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        if (0 == m) {
            return 0;
        }
        n = grid[0].size();
        if (0 == n) {
            return 0;
        }
        d_i = {-1, 0, 1, 0};
        d_j = {0, 1, 0, -1};
        unordered_set<string> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == grid[i][j]) {
                    continue;
                }
                string s;
                s += (to_string(0)+"_"+to_string(0)+"_");
                solve(i, j, 0, 0, s, grid);
                result.insert(s);
            }
        }
        return result.size();
    }
    
private:
    vector<int> d_i;
    vector<int> d_j;
    int m;
    int n;
};
