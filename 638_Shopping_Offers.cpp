class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int result = 0;
        for (int i = 0; i < needs.size(); ++i) {
            result += price[i]*needs[i];
        }
        for (const auto s:special) {
            vector<int> nextNeeds = needs;
            bool canApply = true;
            for (int i = 0; i < s.size()-1; ++i) {
                if (s[i] > nextNeeds[i]) {
                    canApply = false;
                    break;
                } else {
                    nextNeeds[i] -= s[i];
                }
            }
            if (canApply) {
                result = min(result, shoppingOffers(price, special, nextNeeds)+s.back());
            }
        }
        return result;
    }
};
