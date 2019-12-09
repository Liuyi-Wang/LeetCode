static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const string &s, int begin, vector<string> &v) {
        if (begin == s.size()) {
            result.push_back(v);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (dp[begin][i]) {
                v.push_back(s.substr(begin, i-begin+1));
                solve(s, i+1, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
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
        vector<string> v;
        solve(s, 0, v);
        return result;
    }
    
private:
    vector<vector<bool>> dp;
    vector<vector<string>> result;
};
