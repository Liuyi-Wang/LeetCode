static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (0 == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int fb = 0, fe = intervals.size()-1;
        while (fb+1 < fe) {
            int mid = fb+(fe-fb)/2;
            if (intervals[mid][1] < newInterval[0]) {
                fb = mid;
            } else {
                fe = mid-1;
            }
        }
        int begin = 0;
        if (intervals[fe][1] < newInterval[0]) {
            begin = fe;
        } else if (intervals[fb][1] < newInterval[0]) {
            begin = fb;
        } else {
            begin = -1;
        }
        
        int sb = 0, se = intervals.size()-1;
        while (sb+1 < se) {
            int mid = sb+(se-sb)/2;
            if (intervals[mid][0] > newInterval[1]) {
                se = mid;
            } else {
                sb = mid+1;
            }
        }
        int end = 0;
        if (intervals[sb][0] > newInterval[1]) {
            end = sb;
        } else if (intervals[se][0] > newInterval[1]) {
            end = se;
        } else {
            end = intervals.size();
        }
        
        if (static_cast<int>(intervals.size())-1 != begin) {
            newInterval[0] = min(newInterval[0], intervals[begin+1][0]);
        }
        if (0 != end) {
            newInterval[1] = max(newInterval[1], intervals[end-1][1]);
        }
        
        vector<vector<int>> result;
        if (-1 != begin) {
            result.insert(result.end(), intervals.begin(), intervals.begin()+begin+1);
        }
        result.push_back(newInterval);
        if (intervals.size() != end) {
            result.insert(result.end(), intervals.begin()+end, intervals.end());
        }
        return result;
    }
};
