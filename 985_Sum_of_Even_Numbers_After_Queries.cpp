class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto a:A) {
            if (0 == a%2) {
                sum += a;
            }
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            if (0 == abs(A[queries[i][1]])%2 && 0 == abs(queries[i][0])%2) {
                sum += queries[i][0];
            } else if (1 == abs(A[queries[i][1]])%2 && 1 == abs(queries[i][0])%2) {
                sum += A[queries[i][1]]+queries[i][0];
            } else if (0 == abs(A[queries[i][1]])%2 && 1 == abs(queries[i][0])%2) {
                sum -= A[queries[i][1]];
            }
            result[i] = sum;
            A[queries[i][1]] += queries[i][0];
        }
        return result;
    }
};
