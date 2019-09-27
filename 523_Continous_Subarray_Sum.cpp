class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        bool zero = false;
        if (0 == k) {
            for (int i = 0; i < nums.size(); ++i) {
                if (zero && 0 == nums[i]) {
                    return true;
                }
                if (0 == nums[i]) {
                    zero = true;
                    continue;
                }
                zero = false;
            }
            return false;
        }
        k = abs(k);
        if (1 == k) {
            return true;
        }
        unordered_map<int, int> m;
        int sum = 0;
        m[sum] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (zero && 0 == nums[i]) {
                return true;
            }
            if (0 == nums[i]) {
                zero = true;
            } else {
                zero = false;
            }
            
            sum += nums[i];
            m[sum] = i;
            int t = sum-k;
            while (0 <= t) {
                if (m.find(t) != m.end() && i - m[t] >= 2) {
                    return true;
                }
                t -= k;
            }
        }
        return false;
    }
};
