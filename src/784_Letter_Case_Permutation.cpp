static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const string &S, string s) {
        if (s.size() == S.size()) {
            d_result.push_back(s);
            return;
        }
        int i = s.size();
        for (; i < S.size(); ++i) {
            if (isalpha(S[i])) {
                break;
            }
            s += S[i];
        }
        if (s.size() == S.size()) {
            d_result.push_back(s);
            return;
        }
        s += tolower(S[i]);
        solve(S, s);
        s.back() = toupper(S[i]);
        solve(S, s);
    }
    
    vector<string> letterCasePermutation(string S) {
        solve(S, "");
        return d_result;
    }
    
private:
    vector<string> d_result;
};
