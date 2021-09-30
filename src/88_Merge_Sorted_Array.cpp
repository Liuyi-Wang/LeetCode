static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1, i1 = m-1, i2 = n-1;
        while (0 <= i1 && 0 <= i2) {
            if (nums1[i1] > nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }
        while (0 <= i1) {
            nums1[i--] = nums1[i1--];
        }
        while (0 <= i2) {
            nums1[i--] = nums2[i2--];
        }
    }
};
