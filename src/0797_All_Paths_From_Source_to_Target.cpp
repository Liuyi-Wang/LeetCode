/**
 *  Time:
 *  O(2^n n)
 *  Space:
 *  O(2^n n)
 */
class Solution {
    vector<vector<int>> result;
    int n;
    vector<vector<int>> graph;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->graph = graph;
        vector<int> path;
        dfs(0, path);
        return result;
    }
    
    void dfs(int i, vector<int>& path) {
        if (i == n-1) {
            path.push_back(i);
            result.push_back(path);
            path.pop_back();
            return;
        }
        for (auto node:graph[i]) {
            path.push_back(i);
            dfs(node, path);
            path.pop_back();
        }
    }
};
