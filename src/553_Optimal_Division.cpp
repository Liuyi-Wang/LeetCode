static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (1 == nums.size()) {
            return to_string(nums[0]);
        }
        if (2 == nums.size()) {
            return to_string(nums[0])+"/"+to_string(nums[1]);
        }
        string result = to_string(nums[0])+"/(";
        for (int i = 1; i < nums.size()-1; ++i) {
            result += to_string(nums[i])+"/";
        }
        result += to_string(nums.back());
        return result+")";
    }
};
