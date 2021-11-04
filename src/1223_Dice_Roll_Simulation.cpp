/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int MODULE = 1e9+7;
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<unsigned long>> dp(6, vector<unsigned long>(15, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[2][0] = 1;
        dp[3][0] = 1;
        dp[4][0] = 1;
        dp[5][0] = 1;
        
        for (int i = 1; i < n; ++i) {
            vector<vector<unsigned long>> dpi(6, vector<unsigned long>(15, 0));
            for (int j = 0; j < 6; ++j) {
                for (int jj = 0; jj < 6; ++jj) {
                    if (jj == j) {
                        continue;
                    }
                    for (int k = 0; k < rollMax[jj]; ++k) {
                        dpi[j][0] = (dpi[j][0]+dp[jj][k])%MODULE;
                    }
                }
                for (int k = 1; k < rollMax[j]; ++k) {
                    dpi[j][k] = dp[j][k-1];
                }
            }
            dp = dpi;
        }
        unsigned long result = 0;
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < rollMax[j]; ++k) {
                result = (result+dp[j][k])%MODULE;
            }
        }
        return result;
    }
};
