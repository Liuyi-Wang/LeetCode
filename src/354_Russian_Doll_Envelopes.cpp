static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int> &v1,
                                const vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0]; 
        }    
    };
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() < 2) {
            return envelopes.size();
        }
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), less_than());
        dp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); ++i) {
            int h = envelopes[i][1];
            int l = 0, r = dp.size()-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (dp[m] >= h) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            if (dp[l] >= h) {
                dp[l] = h;
            } else if (dp[r] >= h) {
                dp[r] = h;
            } else {
                dp.push_back(h);
            }
        }
        return dp.size();
    }
};
