class Solution {
public:
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i < s.size()+1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j < t.size()+1; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i < s.size()+1; ++i) {
            for (int j = 1; j < t.size()+1; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int edit = min(dp[i-1][j], dp[i][j-1]);
                    edit = min(edit, dp[i-1][j-1]);
                    dp[i][j] = edit+1;
                }
            }
        }
        return dp.back().back();
    }
    
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2);
    }
};
