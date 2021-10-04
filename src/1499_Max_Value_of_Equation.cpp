class Solution {
public:
    struct less_than {
        inline bool operator () (const pair<int, int>& p1,
                                 const pair<int, int>& p2) {
            return p1.first < p2.first;
        }
    };
    
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> yminusx;
        int res = INT_MIN;
        for (int i = 0, n = points.size(); i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            while (!yminusx.empty() && (x - yminusx.front().first > k)) yminusx.pop_front();
            if (!yminusx.empty()) res = max(res, y + x + yminusx.front().second);
            int d = y - x;
            while (!yminusx.empty() && yminusx.back().second <= d) yminusx.pop_back();
            yminusx.push_back({x, d});
        }
        return res;
    }
};
