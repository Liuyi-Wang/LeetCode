class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        unsigned int dp[str1.size()+1][str2.size()+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= str1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= str2.size(); ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j])+1;
                }
            }
        }
        int len = dp[str1.size()][str2.size()];
        string result(len, '*');
        int row = str1.size(), col = str2.size();
        while (row > 0 && col > 0) {
            if (str1[row-1] == str2[col-1]) {
                result[--len] = str1[--row];
                --col;
            } else if (dp[row][col] == dp[row-1][col]+1) {
                result[--len] = str1[--row];           
            } else if (dp[row][col] == dp[row][col-1]+1) {
                result[--len] = str2[--col];           
            }
        }
        while (row > 0) {
            result[--len] = str1[--row];
        }
        while (col > 0) {
            result[--len] = str2[--col];
        }
        return result;
    }
};
