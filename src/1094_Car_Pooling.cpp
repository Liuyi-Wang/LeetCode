/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for (auto trip:trips) {
            v.push_back({trip[1], trip[0]});
            v.push_back({trip[2], -trip[0]});
        }
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        };
        sort(v.begin(), v.end(), cmp);
        int n = 0;
        for (auto p:v) {
            n += p.second;
            if (n > capacity) {
                return false;
            }
        }
        return true;
    }
};
