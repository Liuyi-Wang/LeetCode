static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<long long, int>> dp(A.size());
        unordered_set<int> s(A.begin(), A.end());
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(A[i])-static_cast<long long>(A[j]);
                if (diff > INT_MAX || diff < INT_MIN) {
                    continue;
                }
                result += dp[j].find(diff)!=dp[j].end()?dp[j][diff]:0;
                if (s.find(A[i]+diff) != s.end()) {
                    dp[i][diff] += dp[j][diff]+1;
                }
            }
        }
        return result;
    }
};
