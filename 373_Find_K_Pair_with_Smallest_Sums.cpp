static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        vector<int> nums2_i(nums1.size(), 0);
        int n = min(k, static_cast<int>(nums1.size())*static_cast<int>(nums2.size()));
        while (n > 0) {
            int max_i = -1;
            int max_s = INT_MAX;
            for (int i = 0; i < nums1.size(); ++i) {
                if (nums2_i[i] < nums2.size() && nums1[i]+nums2[nums2_i[i]] < max_s) {
                    max_i = i;
                    max_s = nums1[i]+nums2[nums2_i[i]];
                }
            }
            vector<int> p;
            p.push_back(nums1[max_i]);
            p.push_back(nums2[nums2_i[max_i]++]);
            result.push_back(p);
            --n;
        }
        return result;
    }
};
