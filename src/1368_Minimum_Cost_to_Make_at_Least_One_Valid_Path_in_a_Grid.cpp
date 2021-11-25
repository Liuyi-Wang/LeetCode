/**
 *  Time:
 *  O(MNlogMN)
 *  Space:
 *  O(MN)
 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() > v2.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0, 0});
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!heap.empty()) {
            int x = heap.top()[0];  
            int y = heap.top()[1];  
            int cost = heap.top()[2];  
            heap.pop();
            if (x == m-1 && y == n-1) {
                return cost;
            }
            if (grid[x][y] == 0) {
                continue;
            }
            for (int i = 0; i < dirs.size(); ++i) {
                int X = x+dirs[i][0];
                int Y = y+dirs[i][1];
                if (X < 0 || Y < 0 || X == m || Y == n) {
                    continue;
                }
                if (grid[X][Y] == 0) {
                    continue;
                }
                if ((grid[x][y] == 1 && i == 0) ||
                    (grid[x][y] == 2 && i == 1) ||
                    (grid[x][y] == 3 && i == 2) ||
                    (grid[x][y] == 4 && i == 3)) {
                    heap.push({X, Y, cost});
                } else {
                    heap.push({X, Y, cost+1});
                }
            }
            grid[x][y] = 0;
        }
        return -1;
    }
};
