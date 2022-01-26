/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int low1 = INT_MAX;
        int low2 = INT_MAX;
        int i1, i2;
        for (int j = 0; j < n; ++j) {
            if (low1 > grid[0][j]) {
                low2 = low1;
                low1 = grid[0][j];
                i2 = i1;
                i1 = j;
            } else if (low2 > grid[0][j]) {
                low2 = grid[0][j];
                i2 = j;
            }
        }
        for (int i = 1; i < n; ++i) {
            int l1 = INT_MAX;
            int l2 = INT_MAX;
            int j1, j2;
            for (int j = 0; j < n; ++j) {
                if (i1 != j) {
                    grid[i][j] += low1;
                } else {
                    grid[i][j] += low2;
                }
                if (l1 > grid[i][j]) {
                    l2 = l1;
                    l1 = grid[i][j];
                    j2 = j1;
                    j1 = j;
                } else if (l2 > grid[i][j]) {
                    l2 = grid[i][j];
                    j2 = j;
                }
            }
            low1 = l1;
            low2 = l2;
            i1 = j1;
            i2 = j2;
        }
        int result = INT_MAX;
        for (int j = 0; j < n; ++j) {
            result = min(result, grid.back()[j]);
        }
        return result;
    }
};
