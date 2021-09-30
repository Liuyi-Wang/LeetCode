static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1,
                                const vector<int>& v2) {
            return v1[0] < v2[0];
        }    
    };
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (0 == intervals.size()) {
            return result;   
        }
        sort(intervals.begin(), intervals.end(), less_than());
        vector<int> interval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (interval[1] < intervals[i][0]) {
                result.push_back(interval);
                interval = intervals[i];
            } else {
                interval[1] = max(interval[1], intervals[i][1]);
            }
        }
        result.push_back(interval);
        return result;
    }
};
