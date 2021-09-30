static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        if (s[0] != '0') {
            dp[1] = 1;
        }
        for (int i = 2; i < dp.size(); ++i) {
            if (s[i-1] != '0') {
                dp[i] = dp[i-1];
            }
            if (s[i-2] != '0') {
                int num = atoi(s.substr(i-2, 2).c_str());
                if (num <= 26) {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp.back();
    }
};
