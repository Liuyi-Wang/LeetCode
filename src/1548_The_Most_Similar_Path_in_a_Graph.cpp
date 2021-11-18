/**
 *  Time:
 *  O(nmk)
 *  Space:
 *  O(nm)
 */
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> connects(n, vector<int>());
        for (auto road:roads) {
            connects[road[0]].push_back(road[1]);
            connects[road[1]].push_back(road[0]);
        }
        int m = targetPath.size();
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, pair<int, int>(1, -1)));
        for (int i = 0; i < n; ++i) {
            if (names[i] == targetPath[0]) {
                dp[0][i].first = 0;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pair<int, int> p = {INT_MAX, -1};
                for (int k = 0; k < connects[j].size(); ++k) {
                    if (dp[i-1][connects[j][k]].first < p.first) {
                        p.first = dp[i-1][connects[j][k]].first;
                        p.second = connects[j][k];
                    }
                }
                if (names[j] != targetPath[i]) {
                    ++p.first;
                }
                dp[i][j] = p;
            }
        }
        int id = -1, dis = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dis > dp.back()[i].first) {
                dis = dp.back()[i].first;
                id = i;
            }
        }
        vector<int> result = {id};
        for (int i = m-1; i >= 1; --i) {
            result.push_back(dp[i][id].second);
            id = dp[i][id].second;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
