/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(nn)
 */
class Solution {
    int MODULO = 1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> mxdp(m, vector<long long>(n, 0));
        vector<vector<long long>> mndp(m, vector<long long>(n, 0));
        mxdp[0][0] = grid[0][0];
        mndp[0][0] = grid[0][0];
        long long p = grid[0][0];
        for (int i = 1; i < m; ++i) {
            p *= grid[i][0];
            mxdp[i][0] = p;
            mndp[i][0] = p;
        }
        p = grid[0][0];
        for (int j = 1; j < n; ++j) {
            p *= grid[0][j];
            mxdp[0][j] = p;
            mndp[0][j] = p;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                long long mx = max(grid[i][j]*mxdp[i][j-1], grid[i][j]*mndp[i][j-1]);
                mx = max(mx, grid[i][j]*mxdp[i-1][j]);
                mx = max(mx, grid[i][j]*mndp[i-1][j]);
                long long mn = min(grid[i][j]*mxdp[i][j-1], grid[i][j]*mndp[i][j-1]);
                mn = min(mn, grid[i][j]*mxdp[i-1][j]);
                mn = min(mn, grid[i][j]*mndp[i-1][j]);
                mxdp[i][j] = mx;
                mndp[i][j] = mn;
            }
        }
        if (mxdp.back().back() < 0) {
            return -1;
        }
        return mxdp.back().back()%MODULO;
    }
};
