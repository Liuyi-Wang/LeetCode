class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            vector<int> t = nums1;
            nums1 = nums2;
            nums2 = t;
        }
        unordered_set<int> s;
        for (auto n:nums1) {
            s.insert(n);
        }
        vector<int> result;
        for (auto n:nums2) {
            if (s.find(n) != s.end()) {
                result.push_back(n);
                s.erase(s.find(n));
            }
        }
        return result;
    }
};
