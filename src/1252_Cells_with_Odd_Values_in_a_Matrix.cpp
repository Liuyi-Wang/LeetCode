class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (auto i:indices) {
            ++rows[i[0]];
            ++cols[i[1]];
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (1==(rows[i]+cols[j])%2) {
                    ++result;
                }
            }
        }
        return result;
    }
};
