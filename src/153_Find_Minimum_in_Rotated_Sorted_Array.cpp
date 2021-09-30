static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            if (nums[l] < nums[r]) {
                r= l;
                break;
            }
            int m = l+(r-l)/2;
            if (nums[l] > nums[m]) {
                r = m;
            }
            if (nums[m] > nums[r]) {
                l = m+1;
            }
        }
        return min(nums[l], nums[r]);
    }
};
