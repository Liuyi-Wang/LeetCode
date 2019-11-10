static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    struct less_than {
        inline bool operator() (const Interval* v1,
                                const Interval* v2) {
            return v1->start < v2->start;
        }    
    };
    
    vector<Interval*> merge(vector<Interval*>& intervals) {
        vector<Interval*> result;
        if (0 == intervals.size()) {
            return result;   
        }
        sort(intervals.begin(), intervals.end(), less_than());
        Interval *interval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (interval->end < intervals[i]->start) {
                result.push_back(interval);
                interval = intervals[i];
            } else {
                interval->end = max(interval->end, intervals[i]->end);
            }
        }
        result.push_back(interval);
        return result;
    }
    
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        vector<Interval*> intervals;
        for (const auto &s:schedule) {
            for (const auto &i:s) {
                intervals.push_back(i);
            }
        }
        intervals = merge(intervals);
        vector<Interval*> result;
        for (int i = 0; i < intervals.size()-1; ++i) {
            Interval* interval = new Interval();
            interval->start = intervals[i]->end;
            interval->end = intervals[i+1]->start;
            result.push_back(interval);
        }
        return result;
    }
};
