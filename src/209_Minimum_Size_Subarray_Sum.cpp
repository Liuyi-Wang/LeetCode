static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        int begin = 0, end = 0;
        for (; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= s) {
                result = min(result, end-begin+1);
                sum -= nums[begin++];
            }
        }
        return result==INT_MAX?0:result;
    }
};
