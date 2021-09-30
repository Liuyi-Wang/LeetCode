class Solution {
public:  
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        unordered_set<string> b;
        int n = pow(2, k);
        for (int i = 0; i <= s.size()-k; ++i) {
            b.insert(s.substr(i, k));
            if (b.size() == n) {
                return true;
            }
        }
        return b.size()==n;
    }
};
