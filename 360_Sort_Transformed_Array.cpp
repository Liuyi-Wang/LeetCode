static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result = nums;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = a*nums[i]*nums[i]+b*nums[i]+c;
        }
        int begin = 0, end = nums.size()-1;
        if (a > 0) {
            int i = result.size()-1;
            while (begin <= end) {
                if (nums[begin] > nums[end]) {
                    result[i--] = nums[begin++];
                } else {
                    result[i--] = nums[end--];
                }
            }
        } else {
            int i = 0;
            while (begin <= end) {
                if (nums[begin] < nums[end]) {
                    result[i++] = nums[begin++];
                } else {
                    result[i++] = nums[end--];
                }
            }
        }
        return result;
    }
};
