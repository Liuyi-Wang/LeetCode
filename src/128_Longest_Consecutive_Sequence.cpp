class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num:nums) {
            s.insert(num);
        }
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) == s.end()) {
                continue;
            }
            s.erase(s.find(nums[i]));
            int l = 1;
            while (s.find(nums[i]-l) != s.end()) {
                s.erase(s.find(nums[i]-l));
                ++l;
            }
            int r = 1;
            while (s.find(nums[i]+r) != s.end()) {
                s.erase(s.find(nums[i]+r));
                ++r;
            }
            result = max(result, l+r-1);
        }
        return result;
    }
};
