static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size() && i <= k; ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            }
            hash.insert(nums[i]);
        }
        for (int i = k+1; i < nums.size(); ++i) {
            hash.erase(hash.find(nums[i-k-1]));
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            }
            hash.insert(nums[i]);
        }
        return false;
    }
};
