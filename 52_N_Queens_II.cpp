static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const int &n, vector<bool> &c, vector<bool> &l, vector<bool> &r, int m) {
        if (m == n) {
            ++d_result;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (c[i] || r[i-m+n] || l[i+m+n]) {
                continue;
            }
            c[i] = true;
            r[i-m+n] = true;
            l[i+m+n] = true;
            solve(n, c, l, r, m+1);
            c[i] = false;
            r[i-m+n] = false;
            l[i+m+n] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> c(n, false);
        vector<bool> l(2*n, false);
        vector<bool> r(2*n, false);
        d_result = 0;
        solve(n, c, l, r, 0);
        return d_result;
    }
    
private:
    int d_result;
};
