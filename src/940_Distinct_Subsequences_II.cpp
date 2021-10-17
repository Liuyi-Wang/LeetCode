class Solution {
public:
    int MODULO = 1e9+7;
    int distinctSubseqII(string s) {
        s = "#"+s;
        int n = s.size();
        vector<unsigned long long> dp(n, 0);
        dp[0] = 1;
        vector<int> last(26, 0);
        for (int i = 1; i < n; ++i) {
            int j = last[s[i]-'a'];
            dp[i] = (dp[i-1]*2-((j>=1)?dp[j-1]:0)+MODULO)%MODULO;
            last[s[i]-'a'] = i;
        }
        return dp.back()-1;
    }
};
