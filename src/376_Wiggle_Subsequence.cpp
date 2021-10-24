/**
 ** dp[i][j]
 ** i, subsequence ends at i
 ** j, 0->negtive trend, 1->positive trend
 ** Intuition
 ** Subsequence->ends at i
**/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int result = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                dp[i][1] = dp[i-1][0]+1;
                dp[i][0] = dp[i-1][0];
                result = max(result, dp[i][1]);
            } else if (nums[i] < nums[i-1]) {
                dp[i][0] = dp[i-1][1]+1;
                dp[i][1] = dp[i-1][1];
                result = max(result, dp[i][0]);
            } else {
                dp[i][1] = dp[i-1][1];
                dp[i][0] = dp[i-1][0];
            }
        }
        return result;
    }
};
