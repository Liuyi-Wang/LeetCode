static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        if (0 == n) {
            return 0;
        }
        int result = INT_MIN;
        for (int begin = 0; begin < n; ++begin) {
            vector<int> acc_sum(m, 0);
            for (int end = begin; end < n; ++end) {
                int last_sum = 0;
                int max_sum = INT_MIN;
                for (int row = 0; row < m; ++row) {
                    acc_sum[row] += matrix[row][end];
                    last_sum = max(0, last_sum) + acc_sum[row];
                    max_sum = max(max_sum, last_sum);
                }
                if (max_sum <= k) {
                    result = max(result, max_sum);
                    continue;
                }
                int acc_sum_sum = 0;
                set<int> q = {acc_sum_sum};
                for (int row = 0; row < m; ++row) {
                    acc_sum_sum += acc_sum[row];
                    set<int>::iterator it = q.lower_bound(acc_sum_sum-k);
                    if (it != q.end()) {
                        result = max(result, acc_sum_sum-*it);
                    }
                    q.insert(acc_sum_sum);
                }
            }
        }
        return result;
    }
};
