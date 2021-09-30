static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int M = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, 0)));
        for (int nn = 1; nn <= N; ++nn) {
            for (int ii = 0; ii < m; ++ii) {
                for (int jj = 0; jj < n; ++jj) {
                    long u = (0==ii)?1:dp[ii-1][jj][nn-1];
                    long l = (0==jj)?1:dp[ii][jj-1][nn-1];
                    long d = ((m-1)==ii)?1:dp[ii+1][jj][nn-1];
                    long r = ((n-1)==jj)?1:dp[ii][jj+1][nn-1];
                    dp[ii][jj][nn] = (u+l+d+r)%M;
                }
            }
        }
        return dp[i][j][N];
    }
};
