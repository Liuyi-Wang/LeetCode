static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (0 == nums.size()) {
            return result;
        }
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]+1) {
                continue;
            }
            if (nums[i-1] == last) {
                string s = to_string(last);
                result.push_back(s);
            } else {
                string s = to_string(last)+"->"+to_string(nums[i-1]);
                result.push_back(s);
            }
            last = nums[i];
        }
        if (nums[nums.size()-1] == last) {
            string s = to_string(last);
            result.push_back(s);
        } else {
            string s = to_string(last)+"->"+to_string(nums[nums.size()-1]);
            result.push_back(s);
        }
        return result;
    }
};
