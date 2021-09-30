class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rows(grid[0].size(), 0);
        vector<int> cols(grid.size(), 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                rows[j] = max(rows[j], grid[i][j]);
                cols[i] = max(cols[i], grid[i][j]);
            }
        }
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                result += min(rows[j], cols[i])-grid[i][j];
            }
        }
        return result;
    }
};
