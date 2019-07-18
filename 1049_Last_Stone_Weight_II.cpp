class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /**
         *  There are two stacks of stores, A, B.
         *  |A|+|B| = sum_weight
         *  |A| >= |B|
         *  |B| <= sum_weight/2
         */
        int sum = 0;
        for (auto i:stones) {
            sum += i;
        }
        int cap = sum/2;
        vector<int> row(cap+1, 0);
        vector<vector<int>> dp(stones.size(), row);
        for (int j = stones[0]; j <= cap; ++j) {
            dp[0][j] = stones[0];
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 1; j < stones[i]; ++j) {
               dp[i][j] = dp[i-1][j];
            }
            for (int j = stones[i]; j <= cap; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]);
            }
        }
        return sum-dp.back().back()*2;
    }
};
