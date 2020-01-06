static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> dp(N+1, 0);
        int result = 0;
        for (int i = 0; i < N+1; ++i) {
            if (i < 10) {
                if (0 == i || 1 == i || 8 == i) {
                    dp[i] = 1;
                }
                if (2 == i || 5 == i || 6 == i || 9 == i) {
                    dp[i] = 2;
                    ++result;
                }
            } else {
                if ((2 == dp[i/10] || 2 == dp[i%10]) && (dp[i/10] >= 1 && dp[i%10] >= 1)) {
                    dp[i] = 2;
                    ++result;
                }
                if (1 == dp[i/10] && 1 == dp[i%10]) {
                    dp[i] = 1;
                }
            }
        }
        return result;
    }
};
