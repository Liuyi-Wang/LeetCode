static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        }
        for (int l = 2; l <= s.size(); ++l) {
            for (int i = 0; i <= s.size()-l; ++i) {
                if (s[i] != s[i+l-1]) {
                    continue;
                }
                if (i+1 == i+l-1) {
                    dp[i][i+l-1] = true;
                    continue;
                }
                dp[i][i+l-1] = dp[i+1][i+l-2];
            }
        }
        vector<int> cuts(s.size()+1, 0);
        for (int i = 1; i < cuts.size(); ++i) {
            cuts[i] = i;
        }
        for (int i = 2; i < cuts.size(); ++i) {
            if (dp[0][i-1]) {
                cuts[i] = 1;
                continue;
            }
            for (int j = 0; j <= i-2; ++j) {
                if (dp[j+1][i-1]) {
                    cuts[i] = min(cuts[i], cuts[j+1]+1);
                }
            }
        }
        return cuts.back()-1;
    }
};
