static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (0 == k) {
            return 0;
        }
        int result = 0;
        int prod = 1;
        int l = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (l <= i && prod >= k) {
                prod /= nums[l++];
            }
            result += i-l+1;
        }
        return result;
    }
};
