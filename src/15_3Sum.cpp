class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size();) {
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                if (nums[j]+nums[k] == -nums[i]) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j+1 < k && nums[j+1] == nums[j]) {
                        ++j;
                    }
                    ++j;
                    while (j < k-1 && nums[k-1] == nums[k]) {
                        --k;
                    }
                    --k;
                } else if (nums[j]+nums[k] > -nums[i]) {
                    while (j < k-1 && nums[k-1] == nums[k]) {
                        --k;
                    }
                    --k;
                } else {
                    while (j+1 < k && nums[j+1] == nums[j]) {
                        ++j;
                    }
                    ++j;
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]) {
                ++i;
            }
            ++i;
        }
        return result;
    }
};
