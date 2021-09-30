class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int u = 0, d = n-1, l = 0, r = n-1;
        int num = 1;
        while (u < d && l < r) {
            for (int j = l; j <= r; ++j) {
                result[u][j] = num++;
            }
            for (int i = u+1; i < d; ++i) {
                result[i][r] = num++;
            }
            for (int j = r; j >= l; --j) {
                result[d][j] = num++;
            }
            for (int i = d-1; i > u; --i) {
                result[i][l] = num++;
            }
            ++u;
            --d;
            ++l;
            --r;
        }
        if (u == d) {
            for (int j = l; j <= r; ++j) {
                result[u][j] = num++;
            }
        } else if (l == r) {
            for (int i = u; i <= d; ++i) {
                result[i][l] = num++;
            }
        }
        return result;
    }
};
