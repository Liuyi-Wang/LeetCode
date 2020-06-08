static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(const vector<int>& nums, vector<bool>& v, int k, const int& target, int s, int start) {
        if (0 == k) {
            return true;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (v[i]) {
                continue;
            }
            if (nums[i]+s > target) {
                return false;
            }
            v[i] = true;
            if (nums[i]+s == target) {
                if (solve(nums, v, k-1, target, 0, 0)) {
                    return true;
                }
                v[i] = false;
                return false;
            } else {
                if (solve(nums, v, k, target, s+nums[i], i+1)) {
                    return true;
                }
                v[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (1 == k) {
            return true;
        }
        int sum = 0;
        for (auto n:nums) {
            sum += n;
        }
        if (0 != sum%k) {
            return false;
        }
        vector<bool> v(nums.size(), false);
        sort(nums.begin(), nums.end());
        return solve(nums, v, k, sum/k, 0, 0);
    }
};
