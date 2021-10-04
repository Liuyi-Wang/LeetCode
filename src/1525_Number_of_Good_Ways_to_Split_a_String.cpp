class Solution {
public:
    int numSplits(string s) {
        vector<bool> v(26, false);
        vector<int> dp(s.size(), 0);
        v[s[0]-'a'] = true;
        dp[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (v[s[i]-'a']) {
                dp[i] = dp[i-1];
                continue;
            }
            v[s[i]-'a'] = true;
            dp[i] = dp[i-1]+1;
        }
        v = vector<bool>(26, false);
        v[s[s.size()-1]-'a'] = true;
        int distinct = 1;
        int result = 0;
        if (dp[s.size()-2] == distinct) {
            ++result;
        }
        for (int i = (int)s.size()-2; i >= 1; --i) {
            if (!v[s[i]-'a']) {
                v[s[i]-'a'] = true;
                ++distinct;
            }
            if (dp[i-1] == distinct) {
                ++result;
            }
        }
        return result;
    }
};
