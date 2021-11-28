class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int min_n = INT_MAX, max_n = INT_MIN;
        int min_i, max_i;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (min_n > nums[i]) {
                min_n = nums[i];
                min_i = i;
            }
            if (max_n < nums[i]) {
                max_n = nums[i];
                max_i = i;
            }
        }
        int si = min(max_i, min_i);
        int li = max(max_i, min_i);
        if (si < n-1-li) {
            int result = si+1;
            return result + min(li-si, n-1-li+1);
        } else {
            int result = n-1-li+1;
            return result + min(si+1, li-si);
        }
    }
};
