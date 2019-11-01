static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> n = nums;
        int even = (n.size()+1)/2-1, odd = n.size()-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 == i%2) {
                nums[i] = n[even--];
            } else {
                nums[i] = n[odd--];
            }
        }
    }
};
