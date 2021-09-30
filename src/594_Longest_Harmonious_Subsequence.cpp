static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (0 == nums.size() || 1 == nums.size()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result = 0;
        int l = 0, r = 1;
        while (l <= r && r < nums.size()) {
            if (nums[r]-nums[l] <= 1) {
                ++r;
                continue;
            }
            if (1 == nums[r-1]-nums[l]) {
                result = max(result, r-l);
                cout << result << endl;
                ++l;
                while (nums[l] == nums[l-1]) {
                    ++l;
                }
                continue;
            }
            ++l;
            while (nums[l] == nums[l-1]) {
                ++l;
            }
        }
        if (1 == nums[r-1]-nums[l]) {
            result = max(result, r-l);
        }
        return result;
    }
};
