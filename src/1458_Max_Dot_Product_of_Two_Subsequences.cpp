class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));
        dp[0][0] = nums1[0]*nums2[0];
        int result = dp[0][0];
        for (int i = 1; i < n1; ++i) {
            dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0]);
        }
        result = max(result, dp[n1-1][0]);
        for (int j = 1; j < n2; ++j) {
            dp[0][j] = max(dp[0][j-1], nums1[0]*nums2[j]);
        }
        result = max(result, dp[0][n2-1]);
        for (int i = 1; i < n1; ++i) {
            for (int j = 1; j < n2; ++j) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], max(0, dp[i-1][j-1])+nums1[i]*nums2[j]);
                
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
