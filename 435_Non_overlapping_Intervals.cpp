static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int> &v1,
                                const vector<int> &v2) {
            return v1[0] < v2[0];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (0 == intervals.size()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), less_than());
        int result = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++result;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }
        return result;
    }
};
