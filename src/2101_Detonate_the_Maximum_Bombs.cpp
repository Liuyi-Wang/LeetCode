/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(nn)
 */
class Solution {
    vector<vector<int>> connects;
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        connects = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                long long d = (long long)(bombs[i][0]-bombs[j][0])*(long long)(bombs[i][0]-bombs[j][0])+(long long)(bombs[i][1]-bombs[j][1])*(long long)(bombs[i][1]-bombs[j][1]);
                if ((long long)bombs[i][2]*(long long)bombs[i][2] >= d) {
                    connects[i].push_back(j);
                }
                if ((long long)bombs[j][2]*(long long)bombs[j][2] >= d) {
                    connects[j].push_back(i);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i, n));
        }
        return result;
    }
    
    int dfs(int start, int n) {
        vector<bool> visited(n, false);
        int count = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            start = q.front();
            q.pop();
            if (visited[start]) {
                continue;
            }
            visited[start] = true;
            ++count;
            for (auto connect:connects[start]) {
                if (visited[connect]) {
                    continue;
                }
                q.push(connect);
            }
        }
        return count;
    }
};
