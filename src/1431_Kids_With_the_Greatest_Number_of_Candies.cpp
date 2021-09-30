class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = 0;
        for (auto c:candies) {
            m = max(m, c);
        }
        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i]+extraCandies >= m) {
                result[i] = true;
            }
        }
        return result;
    }
};
