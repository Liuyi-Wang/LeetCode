static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(int node, const vector<vector<int>>& graph) {
        if (-1 == d_status[node]) {
            return false;
        }
        if (1 == d_status[node]) {
            return true;
        }
        if (0 != d_status[node]) {
            return false;
        }
        d_status[node] = 2;
        if (0 == graph[node].size()) {
            d_status[node] = 1;
            return true;
        }
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!solve(graph[node][i], graph)) {
                d_status[node] = -1;
                return false;
            }
        }
        d_status[node] = 1;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        for (int i = 0; i < graph.size(); ++i) {
            if (solve(i, graph)) {
                result.push_back(i);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
    
private:
    unordered_map<int, int> d_status;
};
