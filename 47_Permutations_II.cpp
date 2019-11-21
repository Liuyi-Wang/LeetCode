class Solution {
public:
    void solve(vector<int> nums, int i) {
        if (i == nums.size()) {
            d_result.push_back(nums);
            return;
        }
        solve(nums, i+1);
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] == nums[j]) {
                continue;
            }
            swap(nums[i], nums[j]);
            solve(nums, i+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
