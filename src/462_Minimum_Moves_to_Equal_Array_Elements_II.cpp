class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median;
        if (0 == nums.size()%2) {
            median = (nums[nums.size()/2]+nums[nums.size()/2-1])/2;
        } else {
            median = nums[nums.size()/2];
        }
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += abs(nums[i]-median);
        }
        return result;
    }
};
