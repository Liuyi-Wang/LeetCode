class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        for (int i = 0; i < piles.size(); ++i) {
            dp[i][i] = piles[i];
        }
        for (int l = 2; l <= piles.size(); ++l) {
            for (int i = 0; i < piles.size()+1-l; ++i) {
                int j = i+l-1;
                dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1]);
            }
        }
        return dp.back().back() > 0;
    }
};
