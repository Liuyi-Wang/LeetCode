class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, low = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            low = min(low, prices[i]);
            result = max(result, prices[i]-low);
        }
        return result;
    }
};
