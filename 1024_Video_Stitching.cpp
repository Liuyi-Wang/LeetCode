class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1,
                                const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        }    
    };
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), less_than());
        if (clips[0][0] != 0 || clips.back()[1] < T) {
            return -1;
        }
        vector<int> dp(101, INT_MAX);
        int begin = 0;
        while (0 == clips[begin][0]) {
            ++begin;
        }
        for (int i = 0; i <= clips[begin-1][1]; ++i) {
            dp[i] = 1;
        }
        int pEnd = clips[begin-1][1];
        for (int i = begin; i < clips.size(); ++i) {
            if (clips[i][0] > T) {
                break;
            }
            if (pEnd < clips[i][0]) {
                return -1;
            }
            dp[clips[i][1]] = min(dp[clips[i][1]], dp[clips[i][0]]+1);
            for (int j = clips[i][0]+1; j < clips[i][1]; ++j) {
                dp[j] = min(dp[j], dp[clips[i][1]]);
            }
            pEnd = max(pEnd, clips[i][1]);
        }
        return dp[T];
    }
};
