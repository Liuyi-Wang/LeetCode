static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (0 == prices.size()) {
            return 0;
        }
        vector<int> l(prices.size(), 0);
        int p = 0, low = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            low = min(low, prices[i]);
            p = max(p, prices[i]-low);
            l[i] = p;
        }
        p = 0;
        int high = prices.back();
        int result = 0;
        for (int i = prices.size()-1; i >= 0; --i) {
            high = max(high, prices[i]);
            p = max(p, high-prices[i]);
            result = max(result, l[i]+p);
        }
        return result;
    }
};
