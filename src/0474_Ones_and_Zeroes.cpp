/**
 *  Time:
 *  O(lmn)
 *  Space:
 *  O(mn)
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < strs.size(); ++i) {
            int zero = 0, one = 0;
            for (auto c:strs[i]) {
                if (c == '1') {
                    ++one;
                } else {
                    ++zero;
                }
            }
            for (int j = m; j >= zero; --j) {
                for (int k = n; k >= one; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-zero][k-one]+1);
                }
            }
        }
        return dp.back().back();
    }
};
