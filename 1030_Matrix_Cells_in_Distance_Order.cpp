class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result(R*C, vector<int>(2, 0));
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> q;
        q.push(pair<int, int>(r0, c0));
        int index = 0;
        visited[r0][c0] = true;
        result[index][0] = r0;
        result[index][1] = c0;
        ++index;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first-1 >= 0 && false == visited[p.first-1][p.second]) {
                visited[p.first-1][p.second] = true;
                result[index][0] = p.first-1;
                result[index][1] = p.second;
                ++index;
                q.push(pair<int, int>(p.first-1, p.second));
            }
            if (p.first+1 < R && false == visited[p.first+1][p.second]) {
                visited[p.first+1][p.second] = true;
                result[index][0] = p.first+1;
                result[index][1] = p.second;
                ++index;
                q.push(pair<int, int>(p.first+1, p.second));
            }
            if (p.second-1 >= 0 && false == visited[p.first][p.second-1]) {
                visited[p.first][p.second-1] = true;
                result[index][0] = p.first;
                result[index][1] = p.second-1;
                ++index;
                q.push(pair<int, int>(p.first, p.second-1));
            }
            if (p.second+1 < C && false == visited[p.first][p.second+1]) {
                visited[p.first][p.second+1] = true;
                result[index][0] = p.first;
                result[index][1] = p.second+1;
                ++index;
                q.push(pair<int, int>(p.first, p.second+1));
            }
        }
        return result;
    }
};
