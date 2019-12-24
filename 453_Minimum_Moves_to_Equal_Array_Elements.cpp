class Solution {
public:
    int minMoves(vector<int>& nums) {
        int nmin = nums[0];
        for (const auto &n:nums) {
            nmin = min(nmin, n);
        }
        int result = 0;
        for (const auto &n:nums) {
            result += n-nmin;
        }
        return result;
    }
};
