class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2;) {
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum == target) {
                    return sum;
                }
                if (abs(result-target) > abs(sum-target)) {
                    result = sum;
                }
                if (sum > target) {
                    --r;
                    while (r > l && nums[r] == nums[r+1]) {
                        --r;
                    }
                } else {
                    ++l;
                    while (l < r && nums[l] == nums[l-1]) {
                        ++l;
                    }
                }
            }
            ++i;
            while(i < nums.size()-2 && nums[i] == nums[i-1]) {
                ++i;
            }
        }
        return result;
    }
};
