static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const int &n, int l, int r, string s) {
        if (l == n && r == n) {
            d_result.push_back(s);
            return;
        }
        if (l < n) {
            solve(n, l+1, r, s+'(');
        } 
        if (r < l) {
            solve(n, l, r+1, s+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return d_result;
    }
    
private:
    vector<string> d_result;
};
