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
        vector<int> b(prices.size()+1, 0);
        vector<int> s(prices.size()+1, 0);
        b[1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            b[i+1] = max(b[i], s[i-1]-prices[i]);
            s[i+1] = max(s[i], b[i]+prices[i]);
        }
        return s.back();
    }
};
