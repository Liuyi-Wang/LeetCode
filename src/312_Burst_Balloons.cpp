class Solution {
public:
    void print(vector<vector<int>>& dp) {
        for (auto v:dp) {
            for (auto i:v) {
                cout << i << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> coins(1, 1);
        coins.insert(coins.end(), nums.begin(), nums.end());
        coins.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        /// len = 1
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = coins[i-1]*coins[i]*coins[i+1];
        }
    
        //print(dp);
        
        /// len > 1
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n+1-len; ++i) {
                int j = i+len-1;
                dp[i][j] = max(coins[i-1]*coins[i]*coins[j+1]+dp[i+1][j], 
                               coins[i-1]*coins[j]*coins[j+1]+dp[i][j-1]);
                for (int k = i+1; k <= j-1; ++k) {
                    dp[i][j] = max(dp[i][j], 
                                   coins[i-1]*coins[k]*coins[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
            }
            //print(dp);
        }
        return dp[1][n];
    }
};
