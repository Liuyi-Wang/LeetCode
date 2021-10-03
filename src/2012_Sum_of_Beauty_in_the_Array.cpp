class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxv(n, 0);
        vector<int> minv(n, 0);
        maxv[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            maxv[i] = max(maxv[i-1], nums[i]);
        }
        minv.back() = nums.back();
        for (int i = n-2; i >= 0; --i) {
            minv[i] = min(minv[i+1], nums[i]);
        }
        int result = 0;
        for (int i = 1; i < n-1; ++i) {
            if (maxv[i-1] < nums[i] && nums[i] < minv[i+1]) {
                result += 2;
            } else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ++result;
            }
        }
        return result;
    }
};
