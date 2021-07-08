class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return sol1(nums1, nums2);
    }   

    int sol1(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        int result = 0;
        for (int i = 0; i < n1; ++i) {
            if (nums1[i] == nums2[n2-1]) {
                dp[i][n2-1] = 1;
                result = 1;
            }
        }
        for (int j = 0; j < n2; ++j) {
            if (nums1[n1-1] == nums2[j]) {
                dp[n1-1][j] = 1;
                result = 1;
            }
        }
        for (int i = n1-2; i >= 0; --i) {
            for (int j = n2-2; j >= 0; --j) {
                if (nums1[i] != nums2[j]) {
                    continue;
                }
                dp[i][j] = dp[i+1][j+1]+1;
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
