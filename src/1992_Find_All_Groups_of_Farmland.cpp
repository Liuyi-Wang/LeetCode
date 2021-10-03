class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0) {
                    continue;
                }
                int a = i;
                for (; a < m; ++a) {
                    if (land[a][j] == 0) {
                        break;
                    }
                }
                int b = j;
                for (; b < n; ++b) {
                    if (land[i][b] == 0) {
                        break;
                    }
                }
                result.push_back({i, j, a-1, b-1});
                for (int r = i; r < a; ++r) {
                    for (int c = j; c < b; ++c) {
                        land[r][c] = 0;
                    }
                }
            }
        }
        return result;
    }
};
