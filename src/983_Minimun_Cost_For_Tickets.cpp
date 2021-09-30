class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+1, 0);
        for (auto d:days) {
            dp[d] = 1;
        }
        for (int i = 1; i < days.back()+1; ++i) {
            if (0 == dp[i]) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = dp[i-1]+costs[0];
                dp[i] = min(dp[i], dp[max(0, i-7)]+costs[1]);
                dp[i] = min(dp[i], dp[max(0, i-30)]+costs[2]);
            }
        }
        return dp.back();
    }
};
