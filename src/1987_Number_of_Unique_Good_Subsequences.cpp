class Solution {
public:
    int MODULO = 1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        binary = "#"+binary;
        int n = binary.size();
        vector<unsigned long long> dp(n, 0);
        int last0 = 0, last1 = 0;
        int m = 1;
        bool has0 = false;
        for (; m < n; ++m) {
            if (binary[m] == '1') {
                break;
            }
            has0 = true;
        }
        if (m == n) {
            return 1;
        }
        dp[m] = 1;
        for (int i = m+1; i < n; ++i) {
            if (binary[i] == '0') {
                has0 = true;
            }
            int j = ((binary[i]=='0')?last0:last1);
            dp[i] = (dp[i-1]*2-((j>=1)?dp[j-1]:0)+MODULO)%MODULO;
            if (binary[i] == '0') {
                last0 = i;
            } else {
                last1 = i;
            }
        }
        return dp.back()+((has0>0)?1:0);
    }
};
