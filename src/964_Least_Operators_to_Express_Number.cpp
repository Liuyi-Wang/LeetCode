static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        vector<int> coefs;
        int t = target;
        while (t > 0) {
            coefs.push_back(t%x);
            t /= x;
        }
        vector<vector<int>> dp(coefs.size()+1, vector<int>(2, 0));
        dp[0][1] = 11;
        for (int i = 1; i < dp.size(); ++i) {
            int bit = (i-1)==0?2:(i-1);
            int bit1 = i==0?2:i;
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + bit*coefs[i-1];
            dp[i][1] = min(dp[i-1][0] + (x-coefs[i-1])*bit+bit1,
                           dp[i-1][1] + (x-coefs[i-1])*bit+bit1-2*bit);
        }
        return min(dp.back()[0], dp.back()[1])-1;
    }
};
