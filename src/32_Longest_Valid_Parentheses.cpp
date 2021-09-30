static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size()+1, 0);
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ('(' == s[i]) {
                continue;
            }
            if (i-1-dp[i] >= 0 && '(' == s[i-1-dp[i]]) {
                dp[i+1] = dp[i]+2+dp[i-1-dp[i]];
                result = max(result, dp[i+1]);
            }
        }
        return result;
    }
};
