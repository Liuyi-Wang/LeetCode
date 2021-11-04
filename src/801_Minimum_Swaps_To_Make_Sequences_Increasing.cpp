/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dp0 = 0;
        int dp1 = 1;
        for (int i = 1; i < n; ++i) {
            int dpi0 = INT_MAX;
            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                dpi0 = min(dpi0, dp0);
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                dpi0 = min(dpi0, dp1);
            }
            int dpi1 = INT_MAX;
            if (nums2[i] > nums1[i-1] && nums1[i] > nums2[i-1]) {
                dpi1 = min(dpi1, dp0+1);
            }
            if (nums2[i] > nums2[i-1] && nums1[i] > nums1[i-1]) {
                dpi1 = min(dpi1, dp1+1);
            }
            dp0 = dpi0;
            dp1 = dpi1;
        }
        return min(dp0, dp1);
    }
};
