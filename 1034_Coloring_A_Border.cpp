class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<bool> row(grid[0].size(), false);
        vector<vector<bool>> checked(grid.size(), row);
        stack<pair<int, int>> s;
        s.push(pair<int, int>(r0, c0));
        vector<pair<int, int>> toColor;
        int Color = color;
        color = grid[r0][c0];
        while (!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();
            if (checked[p.first][p.second]) {
                continue;
            }
            checked[p.first][p.second] = true;
            bool border = false;
            if (p.first-1 < 0 || color != grid[p.first-1][p.second]) {
                border = true;
            } else {
                s.push(pair<int, int>(p.first-1, p.second));
            }
            if (p.first+1 >= grid.size() || color != grid[p.first+1][p.second]) {
                border = true;
            } else {
                s.push(pair<int, int>(p.first+1, p.second));
            }    
            if (p.second-1 < 0 || color != grid[p.first][p.second-1]) {
                border = true;
            } else {
                s.push(pair<int, int>(p.first, p.second-1));
            }
            if (p.second+1 >= grid[0].size() || color != grid[p.first][p.second+1]) {
                border = true;
            } else {
                s.push(pair<int, int>(p.first, p.second+1));
            }
            if (border) {
                toColor.push_back(p);
            }
        } 
        for (auto p:toColor) {
            grid[p.first][p.second] = Color;
        }
        return grid;
    }
};
