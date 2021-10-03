class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> counts(101, 0);
        int result = 0;
        for (auto num:nums) {
            if (num+k <= 100) {
                result += counts[num+k];
            }
            if (num-k >= 1) {
                result += counts[num-k];
            }
            ++counts[num];
        }
        return result;
    }
};
