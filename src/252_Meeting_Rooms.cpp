class Solution {
public:
    struct less_than {
        inline bool operator()(const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];    
            }
            return v1[0] < v2[0];
        }    
    };
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), less_than());
        for (int i = 0; i < intervals.size()-1; ++i) {
            if (intervals[i][1] > intervals[i+1][0]) {
                return false;
            }
        }
        return true;
    }
};
