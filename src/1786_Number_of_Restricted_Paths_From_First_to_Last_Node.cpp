/**
 *  Time:
 *  O(ElogV+V)
 *  Space:
 *  O(V)
 */
class Solution {
public:
    int MODULE = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> connects(n+1, vector<pair<int, int>>());
        for (auto edge:edges) {
            connects[edge[0]].push_back({edge[1], edge[2]});
            connects[edge[1]].push_back({edge[0], edge[2]});
        }
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        heap.push({n, 0});
        vector<int> dists(n+1, INT_MAX);
        while (!heap.empty()) {
            int node = heap.top().first;
            int dist = heap.top().second;
            heap.pop();
            if (dists[node] <= dist) {
                continue;
            }
            dists[node] = dist;
            for (auto connect:connects[node]) {
                int newDist = dist+connect.second;
                if (dists[connect.first] <= newDist) {
                    continue;
                }
                heap.push({connect.first, newDist});
            }
        }
        vector<int> counts(n+1, -1);
        return dfs(counts, 1, connects, dists);
    }
    
    long long dfs(vector<int>& counts, int node, vector<vector<pair<int, int>>>& connects, const vector<int>& dists) {
        if (node == counts.size()-1) {
            return 1;
        }
        if (counts[node] != -1) {
            return counts[node];
        }
        long long result = 0;
        for (auto connect:connects[node]) {
            if (dists[node] > dists[connect.first]) {
                result += dfs(counts, connect.first, connects, dists);
                result %= MODULE;
            }
        }
        counts[node] = result;
        return result;
    }
};
