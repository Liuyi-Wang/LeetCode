class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int minVal = INT_MAX;
        int count = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                result += abs(matrix[i][j]);
                minVal = min(minVal, abs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    ++count;
                }
            }
        }
        if (count%2 == 0) {
            return result;
        }
        return result-minVal*2;
    }
};
