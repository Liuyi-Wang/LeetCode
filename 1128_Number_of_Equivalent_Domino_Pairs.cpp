class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> counts(9, vector<int>(9, 0));
        for (int i = 0; i < dominoes.size(); ++i) {
            ++counts[dominoes[i][0]-1][dominoes[i][1]-1];
        }
        int result = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = i; j < 9; ++j) {
                int count = counts[i][j];
                if (i != j) {
                    count += counts[j][i];
                }
                result += count*(count-1)/2;
            }
        }
        return result;
    }
};
