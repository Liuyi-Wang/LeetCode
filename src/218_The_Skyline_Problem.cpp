class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> v;
        for (const auto &b:buildings) {
            v.push_back({b[0], -b[2]});
            v.push_back({b[1], b[2]});
        }
        sort(v.begin(), v.end());
        multiset<int> s;
        s.insert(0);
        vector<vector<int>> result;
        int h = 0;
        for (const auto &p:v) {
            if (p.second < 0) {
                s.insert(-p.second);
                multiset<int>::iterator it = s.end();
                --it;
                if (*it != h) {
                    h = *it;
                    result.push_back({p.first, h});
                }
            } else {
                s.erase(s.find(p.second));
                multiset<int>::iterator it = s.end();
                --it;
                if (*it != h) {
                    h = *it;
                    result.push_back({p.first, h});
                }
            }
        }
        return result;
    }
};
