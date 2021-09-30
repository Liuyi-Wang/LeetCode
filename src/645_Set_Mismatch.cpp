static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 != nums[i]) {
                result.push_back(nums[i]);
                result.push_back(i+1);
            }
        }
        return result;
    }
};
