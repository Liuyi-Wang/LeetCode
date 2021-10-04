class Solution {
public:
    int maxLength(vector<string>& arr) {
        d_result = 0;
        vector<int> masks;
        vector<int> lens;
        for (auto s:arr) {
            int mask = 0;
            bool unique = true;
            for (auto c:s) {
                int i = (1<<(c-'a'));
                if ((mask&i) != 0) {
                    unique = false;
                    break;
                }
                mask |= i;
            }
            if (unique) {
                masks.push_back(mask);
                lens.push_back(s.size());
            }
        }
        dfs(masks, lens, 0, 0, 0);
        return d_result;
    }
    
    void dfs(const vector<int>& masks, const vector<int>& lens, int i, int status, int len) {
        d_result = max(d_result, len);
        if (i == masks.size()) {
            return;
        }
        for (int j = i; j < masks.size(); ++j) {
            if ((status&masks[j]) != 0) {
                continue;
            }
            dfs(masks, lens, j+1, status|masks[j], len+lens[j]);
        }
    }
    
private:
    int d_result;
};
