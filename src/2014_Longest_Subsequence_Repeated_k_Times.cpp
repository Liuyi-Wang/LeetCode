class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        d_counts = vector<int>(26, 0);
        for (auto c:s) {
            ++d_counts[c-'a'];
        }
        dfs(0, "", s, k);
        return d_result;
    }
    
    void dfs (int i, string sub, const string& s, int k) {
        if (i == 7) {
            return;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (d_counts[c-'a'] < k) {
                continue;
            }
            string cur = sub+c;
            //cout << cur << endl;
            if (isValid(cur, s, k)) {
                if (cur.size() >= d_result.size()) {
                    d_result = cur;
                }
                dfs(i+1, cur, s, k);
            }
        }
    }
    
    bool isValid(const string& cur, const string& s, int k) {
        int ic = 0, is = 0, i = 0;
        while (i < k) {
            while (ic < cur.size() && is < s.size()) {
                if (cur[ic] == s[is]) {
                    ++ic;
                } 
                ++is;
            }
            if (ic != cur.size()) {
                return false;
            }
            ic = 0;
            ++i;
        }
        return true;
    }
    
private:
    string d_result;
    vector<int> d_counts;
};
