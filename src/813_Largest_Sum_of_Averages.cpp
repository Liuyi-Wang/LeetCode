static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1]+A[i-1];
        }
        vector<vector<double>> dp(n, vector<double>(K+1, 0));
        for (int i = 0; i < A.size(); ++i) {
            dp[i][1] = (sum[n]-sum[i])/(n-i);
        }
        for (int k = 2; k < K+1; ++k) {
            for (int i = 0; i < A.size(); ++i) {
                for (int j = i+1; j < A.size(); ++j) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+(sum[j]-sum[i])/(j-i));
                }
            }
        }
        return dp[0][K];
    }
};
