/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        vector<vector<string>> dp(2, vector<string>(3, ""));
        sort(digits.begin(), digits.end(), greater());
        dp[0][digits[0]%3] = to_string(digits[0]);
        int index = 0;
        for (int i = 1; i < n; ++i) {
            index = i%2;
            int j = (index+1)%2;
            // Not pick element i
            dp[index] = dp[j];
            // Not pick element j
            if (dp[index][digits[i]%3] < to_string(digits[i])) {
                dp[index][digits[i]%3] = to_string(digits[i]);
            }
            // Try to cat j and i
            for (int k = 0; k < 3; ++k) {
                if (dp[j][k] == "") {
                    continue;
                }
                string t = dp[j][k]+to_string(digits[i]);
                if (t.size() > dp[index][(k+digits[i]%3)%3].size() || 
                    (t.size() == dp[index][(k+digits[i]%3)%3].size() && t > dp[index][(k+digits[i]%3)%3])) {
                    dp[index][(k+digits[i]%3)%3] = t;
                }
            }
        }
        if (dp[index][0].size() > 0 && dp[index][0][0] == '0') {
            return "0";
        }
        return dp[index][0];
    }
};
