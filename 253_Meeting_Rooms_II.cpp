class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];    
            }
            return v1[0] < v2[0];
        }    
    };
    
    struct greater_than {
        inline bool operator() (int i1, int i2) {
            return i1 > i2;
        }    
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals.size();
        }    
        sort(intervals.begin(), intervals.end(), less_than());
        int result = 0;
        vector<int> v;
        make_heap(v.begin(), v.end(), greater_than());
        for (int i = 0; i < intervals.size(); ++i) {
            while (0 != v.size() && v[0] <= intervals[i][0]) {
                pop_heap(v.begin(), v.end(), greater_than());
                v.pop_back();
            }
            v.push_back(intervals[i][1]);
            push_heap(v.begin(), v.end(), greater_than());
            result = max(result, static_cast<int>(v.size()));
        }
        return result;
    }
};
