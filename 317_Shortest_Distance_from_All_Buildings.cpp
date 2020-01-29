static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = INT_MAX;
        vector<int> d_i = {-1, 0, 1, 0};
        vector<int> d_j = {0, 1, 0, -1};
        vector<vector<int>> dists(m, vector<int>(n, 0));
        vector<vector<int>> reach(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (1 != grid[i][j]) {
                    continue;
                }
                ++count;
                vector<vector<bool>> v(m, vector<bool>(n, false));
                pair<int, int> p = {i, j};
                queue<pair<int, int>> q;
                q.push(p);
                v[i][j] = true;
                int dist = 1;
                while (!q.empty()) {
                    int s = q.size();
                    for (int l = 0; l < s; ++l) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int X = x+d_i[k];
                            int Y = y+d_j[k];
                            if (X >= 0 && Y >= 0 && X < m && Y < n && 0 == grid[X][Y] && !v[X][Y]) {
                                dists[X][Y] += dist;
                                ++reach[X][Y];
                                q.push({X, Y});
                                v[X][Y] = true;
                            }
                        }
                    }
                    ++dist;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == grid[i][j] && count == reach[i][j]) {
                    result = min(result, dists[i][j]);
                }
            }
        }
        return result==INT_MAX?(-1):result;
    }
};
