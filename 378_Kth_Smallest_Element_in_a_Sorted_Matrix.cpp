class Solution {
public:
    int smallerEqual(const vector<vector<int>>& matrix, int m) {
        int c = 0;
        int i = matrix.size()-1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] <= m) {
                c += i+1;
                ++j;
            } else {
                --i;
            }
        }
        return c;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int m = l+(r-l)/2;
            int c = smallerEqual(matrix, m);
            if (c < k) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return r;
    }
};
