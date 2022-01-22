/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
    int MODULO = 1e9+7;
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            long long num = 0;
            long long tens = 1;
            for (int j = i; j >= 1; --j) {
                if (tens/10 > k) {
                    break;
                }
                num += (s[j-1]-'0')*tens;
                tens *= 10;
                if (s[j-1] == '0') {
                    continue;
                }
                if (num > k) {
                    break;
                }
                //cout << "num=" << num << endl;
                dp[i] += dp[j-1];
                dp[i] %= MODULO;
            }
            //cout << i << "=" << dp[i] << endl;
        }
        return dp.back();
    }
};
