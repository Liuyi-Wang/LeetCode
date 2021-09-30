static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        result = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i-k];
            sum += nums[i];
            result = max(result, sum);
        }
        return double(result)/k;
    }
};
