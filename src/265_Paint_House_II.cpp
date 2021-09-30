class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (0 == costs.size() || 0 == costs[0].size()) {
            return 0;
        }
        int m1 = 0, m2 = 0, k = -1;
        for (int i = 0; i < costs.size(); ++i) {
            int cm1 = INT_MAX, cm2 = INT_MAX, ck = -1;
            for (int j = 0; j < costs[i].size(); ++j) {
                int cost = costs[i][j]+(j==k?m2:m1);
                if (cost < cm1) {
                    cm2 = cm1;
                    cm1 = cost;
                    ck = j;
                } else if (cost < cm2) {
                    cm2 = cost;
                }
            }
            m1 = cm1;
            m2 = cm2;
            k = ck;
        }
        return m1;
    }
};
