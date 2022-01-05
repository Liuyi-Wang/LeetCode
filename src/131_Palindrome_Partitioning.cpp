/**
 *  Time:
 *  
 *  Space:
 *  O(n^2)
 */
class Solution {
    vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 1) {
            return {{s}};
        }
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }
        }
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i+l-1 < n; ++i) {
                int j = i+l-1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        vector<string> v;
        dfs(dp, s, 0, v);
        return result;
    }
    
    void dfs(const vector<vector<bool>>& dp, const string& s, int i, vector<string>& v) {
        if (i == s.size()) {
            result.push_back(v);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                v.push_back(s.substr(i, j-i+1));
                dfs(dp, s, j+1, v);
                v.pop_back();
            }
        }
    }
};
