/**
 *  Time:
 *  O(n^3)
 *  Space:
 *  O(n^2)
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n-1; ++i) {
            dp[i][i] = nums[i-1]*nums[i]*nums[i+1];
        }
        for (int l = 2; l <= n-2; ++l) {
            for (int i = 1; i < n-l; ++i) {
                int j = i+l-1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n-2];
    }
};
