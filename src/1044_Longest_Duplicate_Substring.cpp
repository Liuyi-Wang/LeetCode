class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 1, r = n-1;
        while (l < r) {
            int mid = l+(r-l)/2+1;
            if (findL(s, mid)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        if (findL(s, l)) {
            return s.substr(l2i[l], l);
        }
        return "";
    }
    
    bool findL(const string& s, int l) {
        unordered_set<uint64_t> visited;
        uint64_t base = 31;
        uint64_t base_pow_len = 1;
        for (int i = 0; i < l; ++i) {
            base_pow_len *= base;
        }
        
        uint64_t hash = 0;
        for (int i = 0; i < s.size(); ++i) {
            hash = hash*base+(s[i]-'a');
            if (i >= l) {
                hash = hash-(s[i-l]-'a')*base_pow_len;
            }
            
            if (i >= l-1) {
                if (visited.find(hash) != visited.end()) {
                    l2i[l] = i-l+1;
                    return true;
                }
                visited.insert(hash);
            }
        }
        return false;
    }
    
private:
    unordered_map<int, int> l2i;
};
