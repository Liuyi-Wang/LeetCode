static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        if (0 == n) {
            return 0;
        }
        vector<vector<int>> ones(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('0' == matrix[i][j]) {
                    continue;
                }
                ones[i][j] = j>0?(ones[i][j-1]+1):1;
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('0' == matrix[i][j]) {
                    continue;
                }
                result = max(result, ones[i][j]);
                int l = ones[i][j];
                for (int k = i-1; k >= 0 && '1' == matrix[k][j]; --k) {
                    l = min(l, ones[k][j]);
                    result = max(result, l*(i-k+1));
                }
            }
        }
        return result;
    }
};
