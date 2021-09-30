class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int l = 0;
        for (int r = 1; l < nums.size() && r < nums.size();) {
            r = max(r, l+1);
            while (r < nums.size() && nums[r]-nums[l] < k) {
                ++r;
            }
            if (r == nums.size()) {
                break;
            }
            if (nums[r]-nums[l] == k) {
                ++result;
            }
            ++l;
            while (l < nums.size() && nums[l] == nums[l-1]) {
                ++l;
            }
        }
        return result;
    }
};
