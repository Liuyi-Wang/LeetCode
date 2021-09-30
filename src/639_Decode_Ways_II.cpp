class Solution {
public:
    int numDecodings(string s) {
        return sol1(s);
    }
    
    int sol1(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int M = 1e9+7;
        int n = s.size();
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        if (s[0] == '*') {
            dp[1] = 9;
        } else {
            dp[1] = 1;
        }
        for (int i = 1; i < n; ++i) {
            int count1 = 1;
            if (s[i] == '0') {
                count1 = 0;
            } else if (s[i] == '*') {
                count1 = 9;
            }
            int count2 = 0;
            if (s[i-1] == '1') {
                if (s[i] == '*') {
                    count2 = 9;
                } else {
                    count2 = 1;
                }
            } else if (s[i-1] == '2') {
                if (s[i] == '*') {
                    count2 = 6;
                } else if (s[i] <= '6') {
                    count2 = 1;
                }
            } else if (s[i-1] == '*') {
                if (s[i] == '*') {
                    count2 = 15;
                } else if (s[i] <= '6') {
                    count2 = 2;
                } else {
                    count2 = 1;
                }
            }
            dp[i+1] = (dp[i]*count1+dp[i-1]*count2)%M;
        }
        return dp.back();
    }
};
