class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> r(100001, vector<pair<int, int>>());
        for (auto ride:rides) {
            r[ride[1]].push_back({ride[0], ride[2]});
        }
        vector<long long> dp(n+1, 0);
        long long result = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < r[i].size(); ++j) {
                int start = r[i][j].first;
                int tip = r[i][j].second;
                dp[i] = max(dp[i], dp[start]+i-start+tip);
            }
            dp[i] = max(dp[i], dp[i-1]);
            result = max(result, dp[i]);
        }
        /*
        for (auto v:dp) {
            cout << v << ",";
        }
        cout << endl;*/
        return result;
    }
};
