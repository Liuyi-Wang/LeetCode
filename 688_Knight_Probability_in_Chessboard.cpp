static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, 0)));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j][0] = 1;
            }
        }
        vector<int> dr = {-2, -2, -1, 1, 2, 2, 1, -1};
        vector<int> dc = {-1, 1, 2, 2, 1, -1, -2, -2};
        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int m = 0; m < 8; ++m) {
                        int R = i+dr[m];
                        int C = j+dc[m];
                        if (R < 0 || C < 0 || R >= N || C >= N) {
                            continue;
                        }
                        dp[i][j][k] += dp[R][C][k-1];
                    }
                }
            }
        }
        double result = dp[r][c][K];
        return result/(pow(8, K));
    }
};
