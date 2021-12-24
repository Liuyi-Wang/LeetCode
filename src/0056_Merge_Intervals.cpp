/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        vector<int> v = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (v[1] < intervals[i][0]) {
                result.push_back(v);
                v = intervals[i];
                continue;
            }
            v[1] = max(v[1], intervals[i][1]);
        }
        result.push_back(v);
        return result;
    }
};
