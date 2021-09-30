class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (0 == numRows) {
            return result;
        }
        result.push_back(vector<int>(1, 1));
        if (1 == numRows) {
            return result;
        }
        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i+1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
