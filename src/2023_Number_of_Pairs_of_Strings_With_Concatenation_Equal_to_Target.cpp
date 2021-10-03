class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (target == nums[i]+nums[j]) {
                    ++result;
                }
                if (target == nums[j]+nums[i]) {
                    ++result;
                }
            }
        }
        return result;
    }
};
