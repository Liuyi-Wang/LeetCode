class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        set<pair<int, int>> exits;
        int m = maze.size();
        int n = maze[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == '.' && (i != entrance[0] || j != entrance[1])) {
                    if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                        exits.insert({i, j});
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '-';
        int step = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                if (exits.find(p) != exits.end()) {
                    return step;
                }
                for (int j = 0; j < 4; ++j) {
                    int X = p.first+dx[j];
                    int Y = p.second+dy[j];
                    if (X < 0 || X >= m || Y < 0 || Y >= n) {
                        continue;
                    }
                    if (maze[X][Y] != '.') {
                        continue;
                    }
                    q.push({X, Y});
                    maze[X][Y] = '-';
                }
            }
            ++step;
        }
        return -1;
    }
};
