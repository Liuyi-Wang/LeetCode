static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<int> &nums, int begin, vector<int> &num) {
        d_result.push_back(num);
        if (nums.size() == begin) {
            return;
        }
        for (int i = begin; i < nums.size();) {
            num.push_back(nums[i]);
            solve(nums, i+1, num);
            num.pop_back();
            ++i;
            while (i < nums.size() && nums[i] == nums[i-1]) {
                ++i;
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> num;
        sort(nums.begin(), nums.end());
        solve(nums, 0, num);
        return d_result;   
    }
    
private:
    vector<vector<int>> d_result;
};
