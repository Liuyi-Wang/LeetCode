/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp0 = 0, dp1 = 0, dp2 = 0;
        if (nums[0]%3 == 0) {
            dp0 = nums[0];
        } else if (nums[0]%3 == 1) {
            dp1 = nums[0];
        } else {
            dp2 = nums[0];
        }
        for (int i = 1; i < nums.size(); ++i) {
            int dpi0 = dp0, dpi1 = dp1, dpi2 = dp2;
            if (nums[i]%3 == 0) {
                dpi0 = max(dpi0, nums[i]);
                if (dp0 != 0) {
                    dpi0 = dp0 + nums[i];
                }
                if (dp1 != 0) {
                    dpi1 = dp1 + nums[i];
                }
                if (dp2 != 0) {
                    dpi2 = dp2 + nums[i];
                }
            } else if (nums[i]%3 == 1) {
                dpi1 = max(dpi1, nums[i]);
                if (dp2 != 0) {
                    dpi0 = max(dpi0, dp2 + nums[i]);
                }
                if (dp0 != 0) {
                    dpi1 = max(dpi1, dp0 + nums[i]);
                }
                if (dp1 != 0) {
                    dpi2 = max(dpi2, dp1 + nums[i]);
                }
            } else {
                dpi2 = max(dpi2, nums[i]);
                if (dp1 != 0) {
                    dpi0 = max(dpi0, dp1 + nums[i]);
                }
                if (dp2 != 0) {
                    dpi1 = max(dpi1, dp2 + nums[i]);
                }
                if (dp0 != 0) {
                    dpi2 = max(dpi2, dp0 + nums[i]);
                }
            }
            dp0 = dpi0;
            dp1 = dpi1;
            dp2 = dpi2;
        }
        return dp0;
    }
};
