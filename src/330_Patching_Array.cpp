static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0;
        int i = 0;
        long long sum = 1;
        while (sum <= n) {
            if (i < nums.size() && nums[i] <= sum) {
                sum += nums[i++];
            } else {
                sum += sum;
                ++result;
            }
        }
        return result;
    }
};
