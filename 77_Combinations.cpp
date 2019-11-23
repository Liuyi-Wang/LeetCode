static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const int &n, int k, int i, vector<int> &v) {
        if (0 == k) {
            d_result.push_back(v);
            return;
        }
        for (int j = i; j <= n-k+1; ++j) {
            v.push_back(j);
            solve(n, k-1, j+1, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(n, k, 1, v);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
