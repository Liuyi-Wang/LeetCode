class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (auto i:arr) {
            ++hash[i];
        }
        unordered_set<int> s;
        for (auto p:hash) {
            if (s.find(p.second) != s.end()) {
                return false;
            }
            s.insert(p.second);
        }
        return true;
    }
};
