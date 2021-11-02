class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        d_m = grid.size();
        d_n = grid[0].size();
        d_dp = vector<vector<vector<short>>>(d_m, vector<vector<short>>(d_n, vector<short>(1<<d_m*d_n, -1)));
        d_directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int state = 0;
        int si = -1, sj = -1;
        for (int i = 0; i < d_m; ++i) {
            for (int j = 0; j < d_n; ++j) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 0 || grid[i][j] == 2) {
                    state |= key(i, j);
                }
            }
        }
        return dfs(grid, si, sj, state);
    }
    
    int key(int i, int j) {
        return 1<<(i*d_n+j);
    }
    
    int dfs(const vector<vector<int>>& grid, int i, int j, int state) {
        if (grid[i][j] == 2) {
            return state == 0;
        }
        if (d_dp[i][j][state] != -1) {
            return d_dp[i][j][state];
        }
        int count = 0;
        for (int k = 0; k < 4; ++k) {
            int I = i+d_directions[k].first;
            int J = j+d_directions[k].second;
            if (I < 0 || J < 0 || I == d_m || J == d_n || grid[I][J] == -1) {
                continue;
            }
            if (state&key(I, J)) {
                count += dfs(grid, I, J, state^key(I, J));
            }
        }
        d_dp[i][j][state] = count;
        return count;
    }
    
private:
    int d_m;
    int d_n;
    vector<vector<vector<short>>> d_dp;
    vector<pair<int, int>> d_directions;
};
