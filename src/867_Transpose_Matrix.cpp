static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> B(n, vector<int>(m, 0)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};
