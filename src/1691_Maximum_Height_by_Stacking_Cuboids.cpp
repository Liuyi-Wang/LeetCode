/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
    vector<vector<int>> all;
public:
    /*
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (int i = 0; i < n; ++i) {
            int l = cuboids[i][0];
            int w = cuboids[i][1];
            int h = cuboids[i][2];
            insert(l, w, h);
        }
        auto cmp=[](const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0] && v1[1] == v2[1]) {
                return v1[2] < v2[2];
            }
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(all.begin(), all.end(), cmp);
        n = all.size();
        vector<int> dp(n, 0);
        dp[0] = all[0][2];
        int result = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = all[i][2];
            for (int j = i-1; j >= 0; --j) {
                if (valid(j, i)) {
                    dp[i] = max(dp[i], dp[j]+all[i][2]);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }*/
    
    bool valid(int j, int i) {
        if (all[j][0] <= all[i][0] && all[j][1] <= all[i][1] && all[j][2] <= all[i][2]) {
            return true;
        }
        return false;
    }
    
    void insert(int l, int w, int h) {
        if (l == w && w == h) {
            all.push_back({l, w, h});
            return;
        }
        if (l == w) {
            all.push_back({l, l, h});
            all.push_back({l, h, l});
            all.push_back({h, l, l});
            return;
        }
        if (l == h) {
            all.push_back({l, l, w});
            all.push_back({l, w, l});
            all.push_back({w, l, l});
            return;
        }
        if (w == h) {
            all.push_back({w, w, l});
            all.push_back({w, l, w});
            all.push_back({l, w, w});
            return;
        }
        all.push_back({l, w, h});
        all.push_back({l, h, w});
        all.push_back({w, l, h});
        all.push_back({w, h, l});
        all.push_back({h, w, l});
        all.push_back({h, l, w});
    }
    
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        int n = cuboids.size();
        for (auto& c:cuboids)
        {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());

        vector<int>dp(n);
        for (int i=0; i<n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j=0; j<i; j++)
                if (cuboids[j][0]<=cuboids[i][0] && cuboids[j][1]<=cuboids[i][1] && cuboids[j][2]<=cuboids[i][2])
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
        }

        int ret = 0;
        for (int i=0; i<n; i++)
            ret = max(ret, dp[i]);        
        return ret;
    }
};
