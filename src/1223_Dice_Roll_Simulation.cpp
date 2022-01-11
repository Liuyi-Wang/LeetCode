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
        vector<vector<vector<unsigned long>>> dp(2, vector<vector<unsigned long>>(6, vector<unsigned long>(15, 0)));
        dp[0][0][0] = 1;
        dp[0][1][0] = 1;
        dp[0][2][0] = 1;
        dp[0][3][0] = 1;
        dp[0][4][0] = 1;
        dp[0][5][0] = 1;
        for (int i = 1; i < n; ++i) {
            int d = i%2;
            int dd = (i-1)%2;
            for (int j = 0; j < 6; ++j) {
                dp[d][j][0] = 0;
                for (int k = 0; k < 6; ++k) {
                    if (j == k) {
                        for (int l = 1; l < rollMax[k]; ++l) {
                            if (l == rollMax[j]) {
                                break;
                            }
                            dp[d][j][l] = dp[dd][k][l-1];
                        }
                    } else {
                        for (int l = 0; l < rollMax[k]; ++l) {
                            dp[d][j][0] += dp[dd][k][l];
                            dp[d][j][0] %= MODULE;
                        }
                    }
                }
            }
        }
        int result = 0;
        int d = (n-1)%2;
        for (int j = 0; j < 6; ++j) {
            for (int l = 0; l < rollMax[j]; ++l) {
                result += dp[d][j][l];
                result %= MODULE;
            }
        }
        return result;
    }
};
