static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(int n, vector<int> &v, int f) {
        if (1 == n) {
            d_result.push_back(v);
            return;
        }
        for (int i = f; i <= n; ++i) {
            if (n%i == 0) {
                v.push_back(i);
                solve(n/i, v, i);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if (1 == n) {
            return d_result;
        }
        vector<int> v;
        solve(n, v, 2);
        d_result.pop_back();
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
