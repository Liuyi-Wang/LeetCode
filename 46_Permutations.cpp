static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& result) {
        if (i == nums.size()-1) {
            result.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            solve(nums, i+1, result);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};
