/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
    int MODULE = 1e9+7;
public:
    int checkRecord(int n) {
        vector<vector<long long>> dp(2, vector<long long>(3, 0));
        dp[1][0] = 1;
        dp[0][1] = 1;
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            int dp00 = (dp[0][0]+dp[0][1]+dp[0][2])%MODULE;
            int dp01 = dp[0][0];
            int dp02 = dp[0][1];
            int dp10 = (dp[0][0]+dp[1][0]+dp[1][1]+dp[1][2]+dp[0][1]+dp[0][2])%MODULE;
            int dp11 = dp[1][0];
            int dp12 = dp[1][1];
            
            dp[0][0] = dp00;
            dp[0][1] = dp01;
            dp[0][2] = dp02;
            dp[1][0] = dp10;
            dp[1][1] = dp11;
            dp[1][2] = dp12;
        }
        return (dp[0][0]+dp[0][1]+dp[0][2]+dp[1][0]+dp[1][1]+dp[1][2])%MODULE;
    }
};
