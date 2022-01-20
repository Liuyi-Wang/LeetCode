/**
 *  Time:
 *  O(nn)
 *  Space;
 *  O(n)
 */
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, 0);
        dp[0] = books[0][1];
        for (int i = 1; i < n; ++i) {
            int t = books[i][0];
            int h = books[i][1];
            dp[i] = dp[i-1]+h;
            for (int j = i-1; j >= 0; --j) {
                t += books[j][0];
                h = max(h, books[j][1]);
                if (t > shelfWidth) {
                    break;
                }
                if (j == 0) {
                    dp[i] = min(dp[i], h);
                } else {
                    dp[i] = min(dp[i], dp[j-1]+h);
                }
            }
        }
        return dp.back();
    }
};
