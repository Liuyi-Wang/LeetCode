static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

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
    
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), less_than());
        unordered_map<int, vector<int>> xy, yx;
        set<pair<int, int>> s;
        for (const auto& p:points) {
            xy[p[0]].push_back(p[1]);
            yx[p[1]].push_back(p[0]);
            s.insert(pair<int, int>(p[0], p[1]));
        }
        int result = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            vector<int>::iterator y_start = upper_bound(xy[points[i][0]].begin(), xy[points[i][0]].end(), points[i][1]);
            vector<int>::iterator x_start = upper_bound(yx[points[i][1]].begin(), yx[points[i][1]].end(), points[i][0]);
            if (x_start == yx[points[i][1]].end() || y_start == xy[points[i][0]].end()) {
                continue;
            }
            if (result <= (*x_start-points[i][0])*(*y_start-points[i][1])) {
                continue;
            }
            for (vector<int>::iterator x_it = x_start; x_it != yx[points[i][1]].end(); ++x_it) {
                for (vector<int>::iterator y_it = y_start; y_it != xy[points[i][0]].end(); ++y_it) {
                    if (result <= (*x_it-points[i][0])*(*y_it-points[i][1])) {
                        continue;
                    }
                    if (s.find(pair<int, int>(*x_it, *y_it)) != s.end()) {
                        result = min(result, (*x_it-points[i][0])*(*y_it-points[i][1]));
                        break;
                    }
                }
            }
        }
        if (result == INT_MAX) {
            return 0;
        }
        return result;
    }
};
