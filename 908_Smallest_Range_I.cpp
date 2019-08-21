class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (1 == A.size()) {
            return 0;
        }
        int max_n = INT_MIN, min_n = INT_MAX;
        for (int a:A) {
            max_n = max(max_n, a);
            min_n = min(min_n, a);
        }
        int result = max_n-min_n;
        return result<=2*K?0:result-2*K;
    }
};
