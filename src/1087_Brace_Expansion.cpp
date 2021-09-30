static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const string &S, int i, string s) {
        if (S.size() == i) {
            d_result.push_back(s);
            return;
        }
        if ('{' == S[i]) {
            ++i;
            int next = S.find('}', i);
            s += '*';
            while ('}' != S[i]) {
                if (',' == S[i]) {
                    ++i;
                    continue;
                }
                s.back() = S[i];
                solve(S, next+1, s);
                ++i;
            }
        } else {
            s += S[i];
            solve(S, i+1, s);
        }
    }
    
    vector<string> expand(string S) {
        solve(S, 0, "");
        sort(d_result.begin(), d_result.end());
        return d_result;
    }
    
private:
    vector<string> d_result;
};
