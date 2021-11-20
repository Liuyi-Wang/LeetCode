/**
 *  Time:
 *  O(ElogE+E)
 *  Space:
 *  O(E+N)
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> connects(n+1, vector<pair<int, int>>());
        for (auto time:times) {
            connects[time[0]].push_back({time[1], time[2]});
        }
        vector<int> distances(n+1, INT_MAX);
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        unordered_set<int> v;
        distances[k] = 0;
        heap.push({k, 0});
        while (!heap.empty()) {
            pair<int, int> p = heap.top();
            heap.pop();
            if (v.find(p.first) != v.end()) {
                continue;
            }
            for (int i = 0; i < connects[p.first].size(); ++i) {
                int distance = p.second + connects[p.first][i].second;
                if (distance < distances[connects[p.first][i].first]) {
                    distances[connects[p.first][i].first] = distance;
                    heap.push({connects[p.first][i].first, distance});
                }
            }
            v.insert(p.first);
        }
        int result = 0;
        for (int i = 1; i < distances.size(); ++i) {
            if (distances[i] == INT_MAX) {
                return -1;
            }
            result = max(result, distances[i]);
        }
        return result;
    }
};
