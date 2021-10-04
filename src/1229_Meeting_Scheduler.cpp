class Solution {
public:
        struct less_than {
        inline bool operator () (const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        }
    };   

    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
                sort(slots1.begin(), slots1.end(), less_than());
        sort(slots2.begin(), slots2.end(), less_than());
        int i1 = 0, i2 = 0;
        while (i1 < slots1.size() && i2 < slots2.size()) {
            if (slots1[i1][1] <= slots2[i2][0]) {
                ++i1;
                continue;
            }
            if (slots2[i2][1] <= slots1[i1][0]) {
                ++i2;
                continue;
            }
            int begin = max(slots1[i1][0], slots2[i2][0]);
            int end = min(slots1[i1][1], slots2[i2][1]);
            if (end-begin >= duration) {
                return {begin, begin+duration};
            }
            if (slots1[i1][1] < slots2[i2][1]) {
                ++i1;
            } else {
                ++i2;
            }
        }
        return {};
    }
};
