static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(int l, int r, string &s) {
        if (l == r) {
            d_result.push_back(s);
            s[l] = '1';
            d_result.push_back(s);
            s[l] = '8';
            d_result.push_back(s);
            s[l] = '0';
            return;
        }
        if (l > r) {
            d_result.push_back(s);
            return;
        }
        if ('0' != s[0]) {
            solve(l+1, r-1, s);
        }
        s[l] = '1';
        s[r] = '1';
        solve(l+1, r-1, s);
        s[l] = '8';
        s[r] = '8';
        solve(l+1, r-1, s);
        s[l] = '6';
        s[r] = '9';
        solve(l+1, r-1, s);
        s[l] = '9';
        s[r] = '6';
        solve(l+1, r-1, s);
        s[l] = '0';
        s[r] = '0';
    }
    
    vector<string> findStrobogrammatic(int n) {
        string s(n, '0');
        solve(0, n-1, s);
        return d_result;
    }
    
private:
    vector<string> d_result;
};
