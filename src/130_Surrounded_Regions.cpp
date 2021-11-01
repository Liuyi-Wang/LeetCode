/**
 * Time Complexity:
 * O(mn)
 * Space Complexity:
 * O(1)
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        d_directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for (int j = 1; j < n-1; ++j) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'o') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        if (board[i][j] == 'O') {
            board[i][j] = 'o';
            q.push({i, j});
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < d_directions.size(); ++i) {
                int X = p.first+d_directions[i].first;
                int Y = p.second+d_directions[i].second;
                if (X < 0 || Y < 0 || X >= board.size() || Y >= board[0].size()) {
                    continue;
                }
                if (board[X][Y] == 'O') {
                    board[X][Y] = 'o';
                    q.push({X, Y});
                }
            }
        }
    }
    
private:
    vector<pair<int, int>> d_directions;
};
