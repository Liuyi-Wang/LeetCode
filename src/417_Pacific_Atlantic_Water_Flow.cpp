static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(queue<pair<int, int>> &q, vector<vector<bool>> &v, const vector<vector<int>> &matrix, bool pq) {
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < dr.size(); ++i) {
                int R = r + dr[i];
                int C = c + dc[i];
                if (R < 0 || C < 0 || R >= matrix.size() || C >= matrix[0].size() || v[R][C] || matrix[r][c] > matrix[R][C]) {
                    continue;
                }
                v[R][C] = true;
                q.push({R, C});
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        queue<pair<int, int>> pq, aq;
        for (int i = 0; i < m; ++i) {
            p[i][0] = true;
            pq.push({i, 0});
            a[i][n-1] = true;
            aq.push({i, n-1});
        }
        for (int j = 0; j < n; ++j) {
            p[0][j] = true;
            pq.push({0, j});
            a[m-1][j] = true;
            aq.push({m-1, j});
        }
        solve(pq, p, matrix, true);
        solve(aq, a, matrix, false);
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[i][j] && a[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
