/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; ++i) {
            sorted.push_back({ages[i], scores[i]});
        }
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        };
        sort(sorted.begin(), sorted.end(), cmp);
        scores.clear();
        ages.clear();
        for (int i = 0; i < n; ++i) {
            scores.push_back(sorted[i].second);
            ages.push_back(sorted[i].second);
        }
        vector<int> dp(n, 0);
        dp[0] = scores[0];
        int result = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = scores[i];
            for (int j = i-1; j >= 0; --j) {
                if (ages[i] == ages[j] || scores[j] <= scores[i]) {
                    dp[i] = max(dp[i], dp[j]+scores[i]);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
