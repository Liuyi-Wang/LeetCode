class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> s2v;
        sort(events.begin(), events.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        });
        int value = 0;
        for (int i = events.size()-1; i >= 0; --i) {
            value = max(value, events[i][2]);
            s2v[events[i][0]] = max(value, s2v[events[i][0]]);
        }
        sort(events.begin(), events.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[1] == v2[1]) {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        });
        value = 0;
        int result = 0;
        for (auto event:events) {
            value = max(value, event[2]);
            map<int, int>::iterator it = s2v.upper_bound(event[1]);
            if (it == s2v.end()) {
                result = max(result, value);
            } else {
                result = max(result, value+it->second);
            }
        }
        return result;
    }
};
