class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counts;
        for (auto a:arr) {
            ++counts[a];
        }
        vector<int> v;
        for (auto it:counts) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int i = 0;
        for (; i < v.size(); ++i) {
            if (k >= v[i]) {
                k -= v[i];
            } else {
                break;
            }
        }
        return v.size()-i;
    }
};
