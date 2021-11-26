/**
 *  Time:
 *  O(Elogn + n)
 *  Space:
 *  O(n+E)
 */
class Solution {
    int MODULE = 1e9+7;
    int n;
public:
    typedef pair<unsigned long long, unsigned long long> PII;
    vector<PII> connects[200];
    unsigned long long dp[200];
    
    int countPaths(int n, vector<vector<int>>& roads) {
        this->n = n;
        for (auto road:roads) {
            connects[road[0]].push_back({road[1], road[2]});
            connects[road[1]].push_back({road[0], road[2]});
        }
        auto cmp = [](const PII& p1, const PII& p2) {
            return p1.second > p2.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
        heap.push({0, 0});
        vector<unsigned long long> dists(n, ULLONG_MAX);
        while (!heap.empty()) {
            int node = heap.top().first;
            unsigned long long dist = heap.top().second;
            heap.pop();
            if (dists[node] <= dist) {
                continue;
            }
            dists[node] = dist;
            for (auto connect:connects[node]) {
                if (dists[connect.first] <= dist+connect.second) {
                    continue;
                }
                heap.push({connect.first, dist+connect.second});
            }
        }
        for (int i = 0; i < 200; ++i) {
            dp[i] = -1;
        }
        return dfs(0, 0, dists);
    }
    
    unsigned long long dfs(int node, unsigned long long dist, const vector<unsigned long long>& dists) {
        if (dist != dists[node]) {
            return 0;
        }
        if (node == n-1) {
            return 1;
        }
        if (dp[node] != -1) {
            return dp[node];
        }
        unsigned long long count = 0;
        for (auto connect:connects[node]) {
            count += dfs(connect.first, dist+connect.second, dists);
            count %= MODULE;
        }
        dp[node] = count;
        return count;
    }
};
