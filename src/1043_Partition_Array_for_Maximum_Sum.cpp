/**
 *  Time:
 *  O(nk)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1]+arr[i];
            int m = arr[i];
            for (int j = 1; j < k; ++j) {
                if (i-j < 0) {
                    break;
                }
                m = max(m, arr[i-j]);
                if (i-j-1 >= 0) {
                    dp[i] = max(dp[i], dp[i-j-1]+m*(j+1));
                } else {
                    dp[i] = max(dp[i], m*(j+1));
                }
            }
        }
        return dp.back();
    }
};
