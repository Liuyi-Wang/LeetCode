class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int result = 0;
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                result = max(result, sum);
                while (nums[prev] != nums[i]) {
                    sum -= nums[prev];
                    s.erase(s.find(nums[prev]));
                    ++prev;
                }
                sum -= nums[prev];
                s.erase(s.find(nums[prev]));
                ++prev;
            }
            sum += nums[i];
            s.insert(nums[i]);
        }
        return max(result, sum);
    }
};
