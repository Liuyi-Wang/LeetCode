static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (d_dp.find(s) != d_dp.end()) {
            return d_dp[s];
        }
        if (0 == s.size()) {
            return {""};
        }
        vector<string> result;
        for (const auto &word:wordDict) {
            if (word != s.substr(0, word.size())) {
                continue;
            }
            vector<string> strs = wordBreak(s.substr(word.size()), wordDict);
            for (const auto &str:strs) {
                result.push_back(word+(str.size()?(" "):(""))+str);
            }
        }
        d_dp[s] = result;
        return result;
    }
     
private:
    unordered_map<string, vector<string>> d_dp;
};
