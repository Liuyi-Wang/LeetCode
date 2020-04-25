static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator () (const pair<int, int> &p1,
                                 const pair<int, int> &p2) {
            if (p1.first == p2.first) {
                p1.second < p2.second;
            }
            return p1.first < p2.first;
        }
    };
    
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> time;
        for (auto s:timePoints) {
            time.push_back({atoi(s.substr(0, 2).c_str()), atoi(s.substr(3, 2).c_str())});
        }
        sort(time.begin(), time.end());
        int result = INT_MAX;
        for (int i = 1; i < time.size(); ++i) {
            result = min(result, (time[i].first-time[i-1].first)*60+time[i].second-time[i-1].second);
        }
        result = min(result, (time[0].first-time.back().first+24)*60+time[0].second-time.back().second);
        return result;
    }
};
