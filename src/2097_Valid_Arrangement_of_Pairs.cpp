/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(V+E)
 */
class Solution {
    unordered_map<int, int> in;
    unordered_map<int, int> out;
    unordered_map<int, vector<int>> to;
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto p:pairs) {
            ++in[p[1]];
            ++out[p[0]];
            to[p[0]].push_back(p[1]);
        }
        int start = -1;
        for (auto it:to) {
            if (out[it.first] - in[it.first] == 1) {
                start = it.first;
            }
        }
        if (start == -1) {
            start = pairs[0][0];
        }
        vector<int> path;
        dfs(start, path);
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (int i = 0; i < path.size()-1; ++i) {
            result.push_back({path[i], path[i+1]});
        }
        return result;
    }
    
    void dfs(int start, vector<int>& path) {
        while (to[start].size() > 0) {
            int next = to[start].back();
            to[start].pop_back();
            dfs(next, path);
        }
        path.push_back(start);
    }
};
