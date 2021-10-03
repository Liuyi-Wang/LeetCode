class Solution {
public:
    /*
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int M = 1e9+7;
        int n = nextVisit.size();
        vector<unsigned long long> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i-1]+1+(dp[i-1]-dp[nextVisit[i-1]])+1+M)%M;
        }
        return dp.back()%M;
    }*/
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int M = 1e9+7;
        unsigned long long day = 0;
        int n = nextVisit.size();
        vector<long long> visited(n, 0);
        vector<long long> fd(n, -1);
        int v = 0;
        int r = 0;
        while (true) {
            if (visited[r] == 0) {
                ++v;
                fd[r] = day;
            }
            if (v == n) {
                break;
            }
            ++visited[r];
            int preR = r;
            if (visited[r]%2 == 0) {
                r = (r+1)%n;
            } else {
                r = nextVisit[r];
            }
            if (r < preR) {
                day = ((day-fd[r])*2+fd[r]+1+M)%M;
                r = preR;
            } else {
                ++day;
            }
        }
        return day%M;
    }
};
