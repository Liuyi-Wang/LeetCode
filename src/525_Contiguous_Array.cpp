static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]*2-1;
            if (hash.find(sum) != hash.end()) {
                result = max(result, i-hash[sum]);
            } else {
                hash[sum] = i;
            }
        }
        return result;
    }
};
