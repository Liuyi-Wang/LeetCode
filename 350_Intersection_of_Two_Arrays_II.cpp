static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            vector<int> t = nums1;
            nums1 = nums2;
            nums2 = t;
        }
        unordered_map<int, int> m;
        for (auto n:nums1) {
            ++m[n];
        }
        vector<int> result;
        for (auto n:nums2) {
            if (m[n] > 0) {
                result.push_back(n);
                --m[n];
            }
        }
        return result;
    }
};
