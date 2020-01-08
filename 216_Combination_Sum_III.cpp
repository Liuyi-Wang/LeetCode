static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const int &k, const int &n, int sum, int i, vector<int> v) {
        if (k == v.size()) {
            if (n == sum) {
                result.push_back(v);
            }
            return;
        }
        for (int j = i; j <= 9; ++j) {
            if (sum+j > n) {
                break;
            }
            vector<int> t = v;
            t.push_back(j);
            solve(k, n, sum+j, j+1, t);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 0, 1, {});
        return result;
    }
    
private:
    vector<vector<int>> result;
};
