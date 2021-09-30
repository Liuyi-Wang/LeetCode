class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        unsigned int m = A.size(), n = A[0].size();
        stack<pair<int, int>> s;
        for (int i = 0; i < m; ++i) {
            if (1 == A[i][0]) {
                s.push(pair<int, int>(i, 0));
            }
            if (1 == A[i][n-1]) {
                s.push(pair<int, int>(i, n-1));
            }
        }
        for (int j = 1; j < n-1; ++j) {
            if (1 == A[0][j]) {
                s.push(pair<int, int>(0, j));
            }
            if (1 == A[m-1][j]) {
                s.push(pair<int, int>(m-1, j));
            }
        }
        while (!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();
            A[p.first][p.second] = 0;
            if (p.first-1 >= 0 && 1 == A[p.first-1][p.second]) {
                s.push(pair<int, int>(p.first-1, p.second));
            }
            if (p.first+1 < m && 1 == A[p.first+1][p.second]) {
                s.push(pair<int, int>(p.first+1, p.second));
            }
            if (p.second-1 >= 0 && 1 == A[p.first][p.second-1]) {
                s.push(pair<int, int>(p.first, p.second-1));
            }
            if (p.second+1 < n && 1 == A[p.first][p.second+1]) {
                s.push(pair<int, int>(p.first, p.second+1));
            }
        }
        int result = 0;
        for (auto row:A) {
            for (auto cell:row) {
                result += cell;       
            }
        }
        return result;
    }
};
