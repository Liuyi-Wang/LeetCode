class Solution {
public:
    struct less_than {
        inline bool operator() (const pair<int, int>& p1,
                                const pair<int, int>& p2) {
            return p1.second < p2.second;
        }    
    };
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> diff(costs.size(), pair<int, int>(0, 0));
        for (int i = 0; i < costs.size(); ++i) {
            diff[i].first = i;
            diff[i].second = costs[i][0]-costs[i][1];
        }
        sort(diff.begin(), diff.end(), less_than());
        int result = 0;
        for (int i = 0; i < costs.size()/2; ++i) {
            result += costs[diff[i].first][0];
        }
        for (int i = costs.size()/2; i < costs.size(); ++i) {
            result += costs[diff[i].first][1];
        }
        return result;
    }
};
