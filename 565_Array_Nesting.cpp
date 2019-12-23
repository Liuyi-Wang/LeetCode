static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> v(nums.size(), false);
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (v[nums[i]]) {
                continue;
            }
            int count = 1;
            int t = i;
            while (nums[t] != i) {
                v[nums[t]] = true;
                ++count;
                t = nums[t];
            }
            result = max(result, count);
        }
        return result;
    }
};
