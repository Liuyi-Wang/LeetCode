class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        unsigned int target = accumulate(nums.begin(), nums.end(), 0);
        if (target%k != 0) {
            return false;
        }
        target /= k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, 0, 0, target, 0, k);
    }
    
    bool dfs(const vector<int>& nums, vector<bool>& visited, int i, int sum, int target, int n, int k) {
        if (n == k) {
            return true;
        }
        if (sum == target) {
            return dfs(nums, visited, 0, 0, target, n+1, k);
        }
        if (sum > target) {
            return false;
        }
        for (int j = i; j < nums.size(); ++j) {
            if (visited[j]) {
                continue;
            }
            visited[j] = true;
            if (dfs(nums, visited, j+1, sum+nums[j], target, n, k)) {
                return true;
            }
            visited[j] = false;
            while (j+1 < nums.size() && nums[j+1] == nums[j]) {
                ++j;
            }
        }
        return false;
    }
};
