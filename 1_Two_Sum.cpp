class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result(2, -1);
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target-nums[i]) != m.end()) {
                result[0] = m[target-nums[i]];
                result[1] = i;
                return result;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
