class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        return dfs(nums, 0, 0, 0);
    }
    
    int dfs(const vector<int>& nums, int start, int index, int sum) {
        if (index == 3) {
            int result = 0;
            for (int i = start; i < nums.size(); ++i) {
                if (sum == nums[i]) {
                    ++result;
                }
            }
            return result;
        }
        int result = 0;
        for (int i = start; i < nums.size()-(3-index); ++i) {
            result += dfs(nums, i+1, index+1, sum+nums[i]);
        }
        return result;
    }
};
