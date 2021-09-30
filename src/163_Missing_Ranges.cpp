static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (0 == nums.size()) {
            if (lower == upper) {
                result.push_back(to_string(lower));
            } else {
                 string s = to_string(lower)+"->"+to_string(upper);
                result.push_back(s);
            }
            return result;
        }
        if (nums[0] > lower) {
            if (nums[0] == lower+1) {
                result.push_back(to_string(lower));
            } else {
                string s = to_string(lower)+"->"+to_string(nums[0]-1);
                result.push_back(s);
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1] || nums[i] == nums[i-1]+1) {
                continue;
            }
            if (nums[i] == nums[i-1]+2) {
                result.push_back(to_string(nums[i-1]+1));
            } else {
                string s = to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1);
                result.push_back(s);
            }
        }
        if (nums.back() < upper) {
            if (nums.back() == upper-1) {
                result.push_back(to_string(upper));
            } else {
                string s = to_string(nums.back()+1)+"->"+to_string(upper);
                result.push_back(s);
            }
        }        
        return result;
    }
};
