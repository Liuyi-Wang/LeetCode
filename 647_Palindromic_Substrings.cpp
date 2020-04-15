static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = s.size();
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        } 
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ++result;
            }
        }
        for (int l = 3; l <= s.size(); ++l) {
            for (int i = 0; i+l <= s.size(); ++i) {
                int j = i+l-1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    ++result;
                }
            }    
        }
        return result;
    }
};
