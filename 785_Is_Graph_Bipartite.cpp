class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> v(graph.size(), 0);
        stack<int> s;
        for (int i = 0; i < graph.size(); ++i) {
            s.push(i);
        }
        while (!s.empty()) {
            int n = s.top();
            s.pop();
            if (0 == v[n]) {
                v[n] = 1;
            }
            for (int i = 0; i < graph[n].size(); ++i) {
                if (0 == v[graph[n][i]]) {
                    v[graph[n][i]] = -v[n];
                    s.push(graph[n][i]);
                } else if (v[graph[n][i]] == v[n]) {
                    return false;
                }
            }       
        }
        return true;
    }
};
