class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (auto a:A) {
            if (s.find(a) != s.end()) {
                return a;
            }
            s.insert(a);
        }
        return 0;
    }
};
