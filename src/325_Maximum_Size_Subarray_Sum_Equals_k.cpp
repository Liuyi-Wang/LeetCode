static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.find(sum) == hash.end()) {
                hash[sum] = i;
            }
            if (hash.find(sum-k) != hash.end()) {
                result = max(result, i-hash[sum-k]);
            }
        }
        return result;
    }
};
