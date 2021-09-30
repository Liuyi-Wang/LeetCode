static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (const auto &word:wordDict) {
            words.insert(word);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (words.find(s.substr(j, i-j)) != words.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
