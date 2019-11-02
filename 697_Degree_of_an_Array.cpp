static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> begin;
        unordered_map<int, int> end;
        unordered_map<int, int> count;
        int degree = 0;
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (begin.find(nums[i]) == begin.end()) {
                begin[nums[i]] = i;
            }
            end[nums[i]] = i;
            ++count[nums[i]];
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                result = end[nums[i]]-begin[nums[i]]+1;
            } else if (count[nums[i]] == degree) {
                result = min(result, end[nums[i]]-begin[nums[i]]+1);
            }
        }
        return result;
    }
};
