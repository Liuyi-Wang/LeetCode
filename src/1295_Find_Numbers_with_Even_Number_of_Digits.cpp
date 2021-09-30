static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto n:nums) {
            int d = 0;
            while (n > 0) {
                n /= 10;
                ++d;
            }
            result += 0==d%2?1:0;
        }
        return result;
    }
};
