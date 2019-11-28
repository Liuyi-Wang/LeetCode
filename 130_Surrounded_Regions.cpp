static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (0 == board.size() || 0 == board[0].size()) {
            return;
        }
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if ('O' == board[i][0]) {
                board[i][0] = 'Y';
                q.push({i, 0});
            }
            if ('O' == board[i][n-1]) {
                board[i][n-1] = 'Y';
                q.push({i, n-1});
            }
        }
        for (int j = 1; j < n; ++j) {
            if ('O' == board[0][j]) {
                board[0][j] = 'Y';
                q.push({0, j});
            }
            if ('O' == board[m-1][j]) {
                board[m-1][j] = 'Y';
                q.push({m-1, j});
            }
        }
        vector<int> d_x = {-1, 0, 1, 0};
        vector<int> d_y = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < d_x.size(); ++i) {
                int X = x + d_x[i];
                int Y = y + d_y[i];
                if (X < 0 || Y < 0 || X >= m || Y >= n || 'O' != board[X][Y]) {
                    continue;
                }
                board[X][Y] = 'Y';
                q.push({X, Y});
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('O' == board[i][j]) {
                    board[i][j] = 'X';
                }
                if ('Y' == board[i][j]) {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
