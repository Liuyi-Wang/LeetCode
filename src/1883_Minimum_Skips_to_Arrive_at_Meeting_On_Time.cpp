/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
    double eps = 1e-8;
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        double minHour = 0, maxHour = 0;
        for (int i = 0; i < n-1; ++i) {
            minHour += (double)dist[i]/(double)speed;
            maxHour += ceil((double)dist[i]/(double)speed);
        }
        minHour += (double)dist.back()/(double)speed;
        maxHour += (double)dist.back()/(double)speed;
        if (minHour > hoursBefore) {
            return -1;
        }
        if (maxHour <= hoursBefore) {
            return 0;
        }
        vector<vector<double>> dp(2, vector<double>(n, -1));
        dp[0][0] = ceil((double)dist[0]/(double)speed);
        dp[0][1] =  (double)dist[0]/(double)speed;
        for (int i = 1; i < n-1; ++i) {
            int cur = i%2;
            int pre = (cur+1)%2;
            double time = (double)dist[i]/(double)speed;
            dp[cur] = vector<double>(n, -1);
            dp[cur][0] = ceil(time+dp[pre][0]-eps);
            for (int j = 1; j < n; ++j) {
                if (dp[pre][j-1] != -1) {
                    dp[cur][j] = time+dp[pre][j-1];
                } else {
                    break;
                }
            }
            for (int j = 1; j < n; ++j) {
                if (dp[pre][j] != -1) {
                    dp[cur][j] = min(dp[cur][j], ceil(time+dp[pre][j]-eps));
                } else {
                    break;
                }
            }
        }
        double time = (double)dist.back()/(double)speed;
        for (int j = 0; j < n; ++j) {
            if (dp[(n-2)%2][j]+time <= hoursBefore) {
                return j;
            }
        }
        return n-1;
    }
};
