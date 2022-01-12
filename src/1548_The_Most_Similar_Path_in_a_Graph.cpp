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
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {1, -1}));
        for (int i = 0; i < n; ++i) {
            if (names[i] == targetPath[0]) {
                dp[0][i].first = 0;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pair<int, int> p = {INT_MAX, -1};
                for (int k = 0; k < connects[j].size(); ++k) {
                    if (p.first > dp[i-1][connects[j][k]].first) {
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
        pair<int, int> p = {INT_MAX, -1};
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (p.first > dp.back()[i].first) {
                p = dp.back()[i];
                index = i;
            }
        }
        vector<int> result = {index};
        int i = m-2;
        while (p.second != -1) {
            result.push_back(p.second);
            p = dp[i--][p.second];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
