class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        unordered_map<int, vector<int>> connects;
        for (auto road:roads) {
            connects[road[0]].push_back(road[1]);
            connects[road[1]].push_back(road[0]);
        }
        unordered_map<int, string> idToName;
        for (int i = 0; i < names.size(); ++i) {
            idToName[i] = names[i];
        }
        int m = targetPath.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, -1}));
        for (int i = 0; i < n; ++i) {
            if (idToName.find(i) == idToName.end() || targetPath[0] != idToName[i]) {
                dp[i][0].first = 1;
            }
        }       
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                pair<int, int> p;
                p.first = INT_MAX;
                for (int k = 0; k < connects[i].size(); ++k) {
                    if (p.first > dp[connects[i][k]][j-1].first) {
                        p.first = dp[connects[i][k]][j-1].first;
                        p.second = connects[i][k];
                    }
                }
                if (idToName.find(i) == idToName.end() || targetPath[j] != idToName[i]) {
                    ++p.first;
                }
                dp[i][j] = p;
            }
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[i][j].first << "|" << dp[i][j].second << ",";
            }
            cout << endl;
        }
        */
        int id = -1, ed = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (ed > dp[i].back().first) {
                ed = dp[i].back().first;
                id = i;
            }
        }
        vector<int> result = {id};
        for (int j = m-1; j >= 1; --j) {
            result.push_back(dp[result.back()][j].second);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
