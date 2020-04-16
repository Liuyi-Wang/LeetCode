static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lens(nums.size(), 1);
        vector<int> counts(nums.size(), 1);
        int longest = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                if (lens[j]+1 == lens[i]) {
                    counts[i] += counts[j];
                } else if (lens[j]+1 > lens[i]) {
                    lens[i] = lens[j]+1;
                    counts[i] = counts[j];
                }
            }
            if (longest == lens[i]) {
                count += counts[i];
            } else if (longest < lens[i]) {
                longest = lens[i];
                count = counts[i];
            }
        }
        return count;
    }
};
