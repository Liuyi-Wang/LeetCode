static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> last(nums.size(), 0);
        vector<int> count(nums.size(), 1);
        int max_c = 1;
        int max_i = 0;
        for (int i = 1; i < nums.size(); ++i) {
            last[i] = i;
            for (int j = i-1; j >= 0; --j) {
                if (nums[i]%nums[j] == 0 && count[i] < count[j]+1) {
                    count[i] = count[j]+1;
                    last[i] = j;
                    if (count[i] > max_c) {
                        max_c = count[i];
                        max_i = i;
                    }
                }
            }
        }
        vector<int> result;
        while (max_i != last[max_i]) {
            result.push_back(nums[max_i]);
            max_i = last[max_i]; 
        }
        result.push_back(nums[max_i]);
        return result;
    }
};
