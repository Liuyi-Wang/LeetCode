class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        if (n == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }
        return max(pickFirst(nums), notPickFirst(nums));
    }
    
    int pickFirst(const vector<int>& nums) {
        int n = nums.size();
        int n0 = nums[0], n1 = nums[0]+nums[2];
        for (int i = 3; i < n-1; ++i) {
            int t0 = max(n0, n1);
            int t1 = nums[i]+n0;
            n0 = t0;
            n1 = t1;
        } 
        return max(n0, n1);
    }
    
    int notPickFirst(const vector<int>& nums) {
        int n = nums.size();
        int n0 = 0, n1 = nums[1];
        for (int i = 2; i < n; ++i) {
            int t0 = max(n0, n1);
            int t1 = nums[i]+n0;
            n0 = t0;
            n1 = t1;
        }
        return max(n0, n1);
    }
};
