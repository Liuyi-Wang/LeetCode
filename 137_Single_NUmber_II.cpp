static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j]>>i)&1;    
            }
            result += (sum%3)<<i; 
        }
        return result;
    }
};
