class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        unsigned int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        vector<int> col(n, 1);
        vector<vector<int> > lens(n, col);
        queue<pair<int, int> > deck;
        deck.push(pair<int, int>(0, 0));
        while (!deck.empty()) {
            pair<int, int> cell = deck.front();
            deck.pop();
            if (cell.first == n-1 && cell.second == n-1) {
                return lens[n-1][n-1];
            }
            if (0 <= cell.first-1 &&
                grid[cell.first-1][cell.second] == 0) {
                deck.push(pair<int, int>(cell.first-1, cell.second));
                lens[cell.first-1][cell.second] = lens[cell.first][cell.second]+1;
                grid[cell.first-1][cell.second] = 1;
            }
            if (0 <= cell.first-1 && cell.second+1 < n &&
                grid[cell.first-1][cell.second+1] == 0) {
                deck.push(pair<int, int>(cell.first-1, cell.second+1));
                lens[cell.first-1][cell.second+1] = lens[cell.first][cell.second]+1;
                grid[cell.first-1][cell.second+1] = 1;
            }
            if (cell.second+1 < n &&
                grid[cell.first][cell.second+1] == 0) {
                deck.push(pair<int, int>(cell.first, cell.second+1));
                lens[cell.first][cell.second+1] = lens[cell.first][cell.second]+1;
                grid[cell.first][cell.second+1] = 1;
            }
            if (cell.first+1 < n && cell.second+1 < n &&
                grid[cell.first+1][cell.second+1] == 0) {
                deck.push(pair<int, int>(cell.first+1, cell.second+1));
                lens[cell.first+1][cell.second+1] = lens[cell.first][cell.second]+1;
                grid[cell.first+1][cell.second+1] = 1;
            }
            if (cell.first+1 < n &&
                grid[cell.first+1][cell.second] == 0) {
                deck.push(pair<int, int>(cell.first+1, cell.second));
                lens[cell.first+1][cell.second] = lens[cell.first][cell.second]+1;
                grid[cell.first+1][cell.second] = 1;
            }
            if (cell.first+1 < n && 0 <= cell.second-1 &&
                grid[cell.first+1][cell.second-1] == 0) {
                deck.push(pair<int, int>(cell.first+1, cell.second-1));
                lens[cell.first+1][cell.second-1] = lens[cell.first][cell.second]+1;
                grid[cell.first+1][cell.second-1] = 1;
            }
            if (0 <= cell.second-1 &&
                grid[cell.first][cell.second-1] == 0) {
                deck.push(pair<int, int>(cell.first, cell.second-1));
                lens[cell.first][cell.second-1] = lens[cell.first][cell.second]+1;
                grid[cell.first][cell.second-1] = 1;
            }
            if (0 <= cell.first-1 && 0 <= cell.second-1 &&
                grid[cell.first-1][cell.second-1] == 0) {
                deck.push(pair<int, int>(cell.first-1, cell.second-1));
                lens[cell.first-1][cell.second-1] = lens[cell.first][cell.second]+1;
                grid[cell.first-1][cell.second-1] = 1;
            }
        }
        return -1;
    }
};
