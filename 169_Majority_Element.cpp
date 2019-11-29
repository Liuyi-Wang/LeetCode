static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (e == nums[i]) {
                ++c;
            } else {
                --c;
            }
            if (0 == c) {
                ++i;
                e = nums[i];
                c = 1;
            }
        }
        return e;
    }
};
