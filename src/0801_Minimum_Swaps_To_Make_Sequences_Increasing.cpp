/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int dp0 = 0, dp1 = 1;
        for (int i = 1; i < nums1.size(); ++i) {
            int swap0 = INT_MAX, swap1 = INT_MAX;
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {
                swap0 = dp0;
                swap1 = dp1+1;
                if (nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]) {
                    swap0 = min(swap0, dp1);
                    swap1 = min(swap1, dp0+1);
                }
            } else {
                swap0 = dp1;
                swap1 = dp0+1;
            }
            dp0 = swap0;
            dp1 = swap1;
        }
        return min(dp0, dp1);
    }
};
