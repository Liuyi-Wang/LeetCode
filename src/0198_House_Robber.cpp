class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int n0 = 0, n1 = nums[0];
        for (int i = 1; i < n; ++i) {
            int t0 = max(n0, n1);
            int t1 = nums[i]+n0;
            n0 = t0;
            n1 = t1;
        }
        return max(n0, n1);
    }
};
