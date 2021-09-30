static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        if (0 == m) {
            return M;
        }
        int n = M[0].size();
        if (0 == n) {
            return M;
        }
        vector<vector<int>> result = M;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 1;
                if (i > 0) {
                    result[i][j] += M[i-1][j];
                    ++count;
                }
                if (i < m-1) {
                    result[i][j] += M[i+1][j];
                    ++count;
                }
                if (j > 0) {
                    result[i][j] += M[i][j-1];
                    ++count;
                }
                if (j < n-1) {
                    result[i][j] += M[i][j+1];
                    ++count;
                }
                if (i > 0 && j > 0) {
                    result[i][j] += M[i-1][j-1];
                    ++count;
                }
                if (i > 0 && j < n-1) {
                    result[i][j] += M[i-1][j+1];
                    ++count;
                }
                if (i < m-1 && j > 0) {
                    result[i][j] += M[i+1][j-1];
                    ++count;
                }
                if (i < m-1 && j < n-1) {
                    result[i][j] += M[i+1][j+1];
                    ++count;
                }
                result[i][j] /= count;
            }
        }
        return result;
    }
};
