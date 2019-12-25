static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = 0;
        int expect = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[m]) {
                expect = 2*nums[m];
                m = i;
            } else {
                expect = max(expect, 2*nums[i]);
            }
        }
        return nums[m]>=expect?m:(-1);
    }
};
