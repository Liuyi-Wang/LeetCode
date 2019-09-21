class Solution {
public:
    /*
    int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; ++i) {
            result *= i;
        }
        return result;
    }
    
    bool valid(int a, int b) {
        int c = sqrt(a+b);
        return c*c == (a+b);
    }
    
    int numSquarefulPerms(vector<int>& A) {
        unsigned int n = A.size();
        unordered_map<int, int> counts;
        for (auto a:A) {
            ++counts[a];
        }
        vector<vector<int>> dp(1<<n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[1<<i][i] = 1;
        }
        for (int c = 1; c < (1<<n); ++c) {
            for (int i = 0; i < n; ++i) {
                if (c & (1<<i)) {
                    for (int j = 0; j < n; ++j) {
                        if (0 == (c & (1<<j)) && valid(A[i], A[j])) {
                            dp[c|(1<<j)][j] += dp[c][i];
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += dp[(1<<n)-1][i];
        }
        for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            result /= factorial(it->second);
        }
        return result;
    }
    */
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        pmt(A, 0, ans);
        return ans;
    }
    void pmt(vector<int> A, int idx, int& ans) {
        if (idx >= A.size()) {
            ++ans;
            return;
        }
        for (int i = idx; i < A.size(); ++i) {
            if (i > idx && A[i] == A[idx]) continue;
            swap(A[i], A[idx]);
            if ((idx == 0) || (idx > 0 && isSquare(A[idx] + A[idx - 1]))) {
                pmt(A, idx + 1, ans);
            }
        }
    }
    bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
    }
};
