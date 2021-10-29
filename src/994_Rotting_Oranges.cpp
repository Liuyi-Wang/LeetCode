class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rotten = 0, fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    ++rotten;
                    q.push({i, j});
                    grid[i][j] = -1;
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        int result = -1;
        while (!q.empty()) {
            ++result;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                for (int j = 0; j < directions.size(); ++j) {
                    int X = p.first+directions[j][0];
                    int Y = p.second+directions[j][1];
                    if (X < 0 || Y < 0 || X >= m || Y >= n) {
                        continue;
                    }
                    if (grid[X][Y] != 1) {
                        continue;
                    }
                    ++count;
                    grid[X][Y] = -1;
                    q.push({X, Y});
                }
            }
        }
        if (count != fresh) {
            return -1;
        }
        return result;
    }
};
