static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int i = 0;
        int result = 0;
        while (end < nums.size()-1) {
            ++result;
            int pre = end;
            for (; i <= pre; ++i) {
                end = max(end, i+nums[i]);
                if ( end >= nums.size()-1) {
                    return result;
                }
            }
        }
        return result;
    }
};
