static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (0 == nums1.size() || 0 == nums2.size()) {
            return {};
        }
        stack<int> s;
        s.push(nums2.back());
        unordered_map<int, int> hash;
        for (int i = nums2.size()-2; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (!s.empty()) {
                hash[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            if (hash.find(nums1[i]) != hash.end()) {
                result[i] = hash[nums1[i]];
            }
        }
        return result;
    }
};
