static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= int(prices.size())-1) {
            int result = 0;
            for (int i = 1; i < prices.size(); ++i) {
                result += max(prices[i]-prices[i-1], 0);
            }
            return result;
        }
        vector<int> on(prices.size(), 0);
        vector<int> dp(prices.size(), 0);
        for (int i = 0; i < k; ++i) {
            vector<int> ton = on;
            vector<int> tdp = dp;
            for (int j = 1; j < prices.size(); ++j) {
                int diff = prices[j]-prices[j-1];
                ton[j] = max(ton[j-1]+diff, dp[j-1]+max(0, diff));
                tdp[j] = max(ton[j], tdp[j-1]);
            }
            on = ton;
            dp = tdp;
        }
        return dp.back();
    }
};
