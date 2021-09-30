static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return result;
        }
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m-1, l = 0, r = n-1;
        while (u < d && l < r) {
            for (int j = l; j <= r; ++j) {
                result.push_back(matrix[u][j]);
            }
            for (int i = u+1; i < d; ++i) {
                result.push_back(matrix[i][r]);
            }
            for (int j = r; j >= l; --j) {
                result.push_back(matrix[d][j]);
            }
            for (int i = d-1; i > u; --i) {
                result.push_back(matrix[i][l]);
            }
            ++u;
            --d;
            ++l;
            --r;
        }
        if (u == d) {
            for (int j = l; j <= r; ++j) {
                result.push_back(matrix[u][j]);
            }
        } else if (l == r) {
            for (int i = u; i <= d; ++i) {
                result.push_back(matrix[i][r]);
            }
        }
        return result;
    }
};
