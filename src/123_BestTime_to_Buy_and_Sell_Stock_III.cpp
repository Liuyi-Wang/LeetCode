class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return sol1(prices);
    }
    
    int sol1(const vector<int>& prices) {
        int n = prices.size();
        vector<int> l2r(n, 0);
        int low = prices[0];
        for (int i = 1; i < n; ++i) {
            l2r[i] = max(l2r[i-1], prices[i]-low);
            low = min(low, prices[i]);
        }
        int high = prices.back();
        int result = l2r.back();
        int profit = 0;
        for (int i = n-2; i >= 0; --i) {
            profit = max(profit, high-prices[i]);
            high = max(high, prices[i]);
            result = max(result, l2r[i]+profit);
        }
        return result;
    }
};
