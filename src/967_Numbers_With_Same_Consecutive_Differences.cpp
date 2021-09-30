static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(int num, int n, const int& N, const int& K) {
        if (N == n) {
            d_result.insert(num);
            return;
        }
        int last = num%10;
        if (last-K >= 0) {
            solve(num*10+last-K, n+1, N, K);
        }
        if (last+K <= 9) {
            solve(num*10+last+K, n+1, N, K);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        for (int i = 1; i <= 9; ++i) {
            solve(i, 1, N, K);
        }
        vector<int> result(d_result.begin(), d_result.end());
        if (N == 1) {
            result.push_back(0);
        }
        return result;
    }
    
private:
    set<int> d_result;
};
