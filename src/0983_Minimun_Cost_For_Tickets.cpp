/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);
        dp[0] = min(costs[0], costs[1]);
        dp[0] = min(dp[0], costs[2]);
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1]+costs[0];
            auto it = lower_bound(days.begin(), days.begin()+i, days[i]-6);
            if (it == days.begin()) {
                dp[i] = min(dp[i], costs[1]);
            } else {
                --it;
                dp[i] = min(dp[i], costs[1]+dp[it-days.begin()]);
            }
            it = lower_bound(days.begin(), days.begin()+i, days[i]-29);
            if (it == days.begin()) {
                dp[i] = min(dp[i], costs[2]);
            } else {
                --it;
                dp[i] = min(dp[i], costs[2]+dp[it-days.begin()]);
            }
        }
        return dp.back();
    }
};
