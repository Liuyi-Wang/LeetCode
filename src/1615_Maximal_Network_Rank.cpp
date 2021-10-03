class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> hash;
        set<pair<int, int>> edges;
        for (auto road:roads) {
            ++hash[road[0]];
            ++hash[road[1]];
            if (road[0] < road[1]) {
                edges.insert({road[0], road[1]});
            } else {
                edges.insert({road[1], road[0]});
            }
        }
        int result = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (edges.find({i, j}) == edges.end()) {
                    result = max(result, hash[i]+hash[j]);
                } else {
                    result = max(result, hash[i]+hash[j]-1);
                }
            }
        }
        return result;
    }
};
