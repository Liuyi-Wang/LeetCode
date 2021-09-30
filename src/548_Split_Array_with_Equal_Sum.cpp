static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) {
            return false;
        }
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i-1]+nums[i];
        }
        for (int j = 3; j < nums.size()-3; ++j) {
            unordered_set<int> s;
            for (int i = 1; i <= j-2; ++i) {
                int s1 = sums[i-1];
                int s2 = sums[j-1]-sums[i];
                if (s1 == s2) {
                    s.insert(s1);
                }
            }
            for (int i = j+2; i < nums.size()-1; ++i) {
                int s1 = sums.back()-sums[i];
                int s2 = sums[i-1]-sums[j];
                if (s1 == s2 && s.find(s1) != s.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
