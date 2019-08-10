class Solution {
public:
    typedef pair<int, int> Cell;
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Cell> q;
        int fresh = 0;
        map<pair<int, int>, int> m;
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (1 == grid[i][j]) {
                    ++fresh;
                } else if (2 == grid[i][j]) {
                    q.push(Cell(i, j));
                    m[Cell(i, j)] = 0;
                }
            }
        }
        if (0 == fresh) {
            return 0;
        }
        while (!q.empty()) {
            Cell c = q.front();
            int i = c.first, j = c.second;
            q.pop();
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
                continue;
            }
            if (-1 == grid[i][j] || 0 == grid[i][j]) {
                continue;
            }
            if (1 == grid[i][j]) {
                result = max(result, m[c]);
                grid[i][j] = 2;
                --fresh;
                q.push(c);
                continue;
            }
            if (m.find(Cell(i-1, j)) == m.end()) {
                q.push(Cell(i-1, j));
                m[Cell(i-1, j)] = m[c]+1;
            }
            if (m.find(Cell(i+1, j)) == m.end()) {
                q.push(Cell(i+1, j));
                m[Cell(i+1, j)] = m[c]+1;
            }
            if (m.find(Cell(i, j-1)) == m.end()) {
                q.push(Cell(i, j-1));
                m[Cell(i, j-1)] = m[c]+1;
            }
            if (m.find(Cell(i, j+1)) == m.end()) {
                q.push(Cell(i, j+1));
                m[Cell(i, j+1)] = m[c]+1;
            }
            grid[i][j] = -1;
        }
        if (0 != fresh) {
            return -1;
        }
        return result;
    }
};
