/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        int n = nums.size();
        dp[0][nums[0]%3] = nums[0];
        int index = 0;
        for (int i = 1; i < n; ++i) {
            index = i%2;
            dp[index][0] = dp[(index+1)%2][0];
            dp[index][1] = dp[(index+1)%2][1];
            dp[index][2] = dp[(index+1)%2][2];
            
            if (nums[i]%3 == 0) {
                dp[index][0] = max(dp[index][0], nums[i]);
                
                dp[index][0] = max(dp[index][0], (0==dp[(index+1)%2][0])?0:(dp[(index+1)%2][0]+nums[i]));
                dp[index][1] = max(dp[index][1], (0==dp[(index+1)%2][1])?0:(dp[(index+1)%2][1]+nums[i]));
                dp[index][2] = max(dp[index][2], (0==dp[(index+1)%2][2])?0:(dp[(index+1)%2][2]+nums[i]));
            } else if (nums[i]%3 == 1) {
                dp[index][1] = max(dp[index][1], nums[i]);
                
                dp[index][0] = max(dp[index][0], (0==dp[(index+1)%2][2])?0:(dp[(index+1)%2][2]+nums[i]));
                dp[index][1] = max(dp[index][1], (0==dp[(index+1)%2][0])?0:(dp[(index+1)%2][0]+nums[i]));
                dp[index][2] = max(dp[index][2], (0==dp[(index+1)%2][1])?0:(dp[(index+1)%2][1]+nums[i]));
            } else {
                dp[index][2] = max(dp[index][2], nums[i]);
                
                dp[index][0] = max(dp[index][0], (0==dp[(index+1)%2][1])?0:(dp[(index+1)%2][1]+nums[i]));
                dp[index][1] = max(dp[index][1], (0==dp[(index+1)%2][2])?0:(dp[(index+1)%2][2]+nums[i]));
                dp[index][2] = max(dp[index][2], (0==dp[(index+1)%2][0])?0:(dp[(index+1)%2][0]+nums[i]));
            }
            
            //cout << dp[index][0] << "," << dp[index][1] << "," << dp[index][2] << endl;
        }
        return dp[index][0];
    }
};
