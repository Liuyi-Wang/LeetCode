static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = dp[i-1][0]+1;
        }
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = dp[0][j-1]+1;
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j])+1;
                }
            }
        }
        return dp.back().back();
    }
};
