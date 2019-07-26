class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<vector<int>> len(A.size(), vector<int>(A.size(), 2));
        vector<int> index(10001, -1);
        index[A[0]] = 0;
        int result = 2;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = i+1; j < A.size(); ++j) {
                int prev = A[i]*2-A[j];
                if (prev < 0 || prev > 10000 || -1 == index[prev]) {
                    continue;        
                }
                len[i][j] = len[index[prev]][i] + 1;
                result = max(result, len[i][j]);
            }
            index[A[i]] = i;
        }
        return result;
    }
};
