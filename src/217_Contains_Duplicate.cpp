static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto num:nums) {
            if (hash.find(num) != hash.end()) {
                return true;
            }
            hash.insert(num);
        }
        return false;
    }
};
