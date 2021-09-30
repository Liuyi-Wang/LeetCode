class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> v(m, vector<long long>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (1 == obstacleGrid[i][0]) {
                break;
            }
            v[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (1 == obstacleGrid[0][j]) {
                break;
            }
            v[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (1 == obstacleGrid[i][j]) {
                    v[i][j] = 0;
                } else {
                    v[i][j] = v[i-1][j]+v[i][j-1];
                }
            }
        }
        return v.back().back();
    }
};
