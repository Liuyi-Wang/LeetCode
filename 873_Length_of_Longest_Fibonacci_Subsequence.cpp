static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int result = 0;
        unordered_map<int, int> m;
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        for (int i = 0; i < A.size(); ++i) {
            m[A[i]] = i;
            for (int j = 0; j < i; ++j) {
                int k = m.count(A[i] - A[j])?m[A[i]-A[j]]:-1;
                dp[j][i] = (A[i]-A[j] < A[j] && k >= 0)?(dp[k][j]+1):2;
                result = max(result, dp[j][i]);
            }
        }
        return result<3?0:result;
    }
};
