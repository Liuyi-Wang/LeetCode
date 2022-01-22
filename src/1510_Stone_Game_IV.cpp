/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
    int dp[100001];
public:
    bool winnerSquareGame(int n) {
        int sq = sqrt(n);
        if (sq*sq == n) {
            return true;
        }
        dp[0] = -1;
        dp[1] = 1;
        bool r = dfs(n);
        return r == 1;
    }
    
    bool dfs(int n) {
        if (dp[n] != 0) {
            return dp[n] == 1;
        }
        for (int i = 1; i*i <= n; ++i) {
            if (!dfs(n-i*i)) {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = -1;
        return false;
    }
};
