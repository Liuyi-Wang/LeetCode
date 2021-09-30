static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int result = (1<<(n-1))*m;
        for (int i = 1; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < m; ++j) {
                if (A[j][0] == A[j][i]) {
                    ++count;
                }
            }
            result += max(count, m-count)*(1<<(n-i-1));
        }
        return result;
    }
};
