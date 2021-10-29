class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> hash = vector<vector<int>>(26, vector<int>());
        for (int i = 0; i < ring.size(); ++i) {
            hash[ring[i]-'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<int> firstKey = hash[key[0]-'a'];
        for (int i = 0; i < firstKey.size(); ++i) {
            dp[0][firstKey[i]] = min(firstKey[i], n-firstKey[i]);
        }
        for (int i = 1; i < m; ++i) {
            vector<int> currentKey = hash[key[i]-'a'];
            vector<int> lastKey = hash[key[i-1]-'a'];
            for (int j = 0; j < currentKey.size(); ++j) {
                for (int k = 0; k < lastKey.size(); ++k) {
                    int step = min(abs(currentKey[j]-lastKey[k]), n-abs(currentKey[j]-lastKey[k]))+dp[i-1][lastKey[k]];
                    dp[i][currentKey[j]] = min(dp[i][currentKey[j]], step);
                }
            }
        }
        int result = INT_MAX;
        vector<int> lastKey = hash[key.back()-'a'];
        for (int j = 0; j < lastKey.size(); ++j) {
            result = min(result, dp.back()[lastKey[j]]);
        }
        return result+key.size();
    }
};
