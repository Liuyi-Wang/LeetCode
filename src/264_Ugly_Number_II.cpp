static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(1, 1);
        --n;
        int i2 = 0, i3 = 0, i5 = 0;
        while (n > 0) {
            int n2 = nums[i2]*2, n3 = nums[i3]*3, n5 = nums[i5]*5;
            int num = min(n2, min(n3, n5));
            if (num == n2) {
                ++i2;
            }
            if (num == n3) {
                ++i3;
            }
            if (num == n5) {
                ++i5;
            }
            nums.push_back(num);
            --n;
        }
        return nums.back();
    }
};
