class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int result = 0;
        bool repeat = false;
        int sum = cost[0];
        int m = cost[0];
        for (int i = 1; i < cost.size(); ++i) {
            if (s[i] != s[i-1]) {
                if (repeat) {
                    result += sum-m;
                    repeat = false;
                }
                sum = cost[i];
                m = cost[i];
                continue;
            }
            sum += cost[i];
            m = max(m, cost[i]);
            repeat = true;
        }
        if (repeat) {
            result += sum-m;
        }
        return result;
    }
};
