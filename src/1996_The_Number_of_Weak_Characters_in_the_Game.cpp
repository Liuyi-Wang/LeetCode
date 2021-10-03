class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& p1, const vector<int>& p2) {
            if (p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] < p2[0];
        });
        multiset<int> s;
        for (auto property:properties) {
            s.insert(property[1]);
        }
        int result = 0;
        for (int i = 0; i < properties.size(); ++i) {
            int a = properties[i][0];
            int d = properties[i][1];
            int j = i;
            s.erase(s.find(properties[i][1]));
            while (i+1 < properties.size() && properties[i+1][0] == a) {
                s.erase(s.find(properties[i+1][1]));
                ++i;
            }
            if (!s.empty()) {
                multiset<int>::iterator it = s.end();
                --it;
                for (; j <= i; ++j) {
                    if (properties[j][1] < *it) {
                        ++result;
                    }
                }
            } else {
                break;
            }
        }
        return result;
    }
};
