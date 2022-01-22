/**
 *  Time:
 *  O(nnk)
 *  Space:
 *  O(nk)
 */
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        int K = k+1;
        vector<vector<int>> dp(n, vector<int>(K, INT_MAX/2));
        int mx = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            sum += nums[i];
            dp[i][0] = mx*(i+1)-sum;
        }
        for (int j = 0; j < K; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (k = 1; k < K; ++k) {
                mx = 0;
                sum = 0;
                for (int j = i; j >= 1; --j) {
                    mx = max(mx, nums[j]);
                    sum += nums[j];
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1]+mx*(i-j+1)-sum);
                }
            }
        }
        int result = INT_MAX;
        for (int k = 0; k < K; ++k) {
            result = min(result, dp.back()[k]);
        }
        return result;
    }
};
