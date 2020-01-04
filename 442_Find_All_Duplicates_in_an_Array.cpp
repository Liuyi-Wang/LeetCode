class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int j = abs(nums[i])-1;
            if (nums[j] < 0) {
                result.push_back(abs(nums[i]));
            } else {
                nums[j] = -nums[j];
            }
        }
        return result;
    }
};
