/**
 *  Time:
 *  O(mn)
 *  Space:
 *  O(200*200+)
 */
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    bool visited[199][199];
    int grid[199][199];
    pair<int, int> target;
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    string uldr = "ULDR";
public:
    void constructGrid(GridMaster &master, int i, int j) {
        if (master.isTarget()) {
            target = {i, j};
            visited[i][j] = true;
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < dirs.size(); ++k) {
            int I = i + dirs[k].first;
            int J = j + dirs[k].second;
            if (I < 0 || J < 0 || I >= 199 || J >= 199) {
                continue;
            }
            if (visited[I][J]) {
                continue;
            }
            if (!master.canMove(uldr[k])) {
                continue;
            }
            grid[I][J] = master.move(uldr[k]);
            if (grid[I][J] != -1) {
                //cout << I << "," << J << "=" << grid[I][J] << endl;
                constructGrid(master, I, J);
                master.move(uldr[(k+2)%4]);
            }
        }
    }
    
    int findShortestPath(GridMaster &master) {
        for (int i = 0; i < 199; ++i) {
            for (int j = 0; j < 199; ++j) {
                grid[i][j] = -1;
            }
        }
        constructGrid(master, 99, 99);
        
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() > v2.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({99, 99, 0});
        while (!heap.empty()) {
            int x = heap.top()[0];
            int y = heap.top()[1];
            int cost = heap.top()[2];
            heap.pop();
            if (x == target.first && y == target.second) {
                return cost;
            }
            if (!visited[x][y]) {
                continue;
            }
            visited[x][y] = false;
            for (int k = 0; k < dirs.size(); ++k) {
                int X = x + dirs[k].first;
                int Y = y + dirs[k].second;
                if (X < 0 || Y < 0 || X >= 199 || Y >= 199) {
                    continue;
                }
                if (grid[X][Y] == -1) {
                    continue;
                }
                if (!visited[X][Y]) {
                    continue;
                }
                heap.push({X, Y, cost+grid[X][Y]});
            }
        }
        return -1;
    }
};
