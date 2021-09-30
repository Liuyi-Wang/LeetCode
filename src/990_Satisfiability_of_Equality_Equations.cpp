class Solution {
public:
    char find(char c) {
        char root = c;
        while (root != d_parent[root-'a']) {
            root = d_parent[root-'a'];
        }
        char node = c, tmp;
        while (d_parent[node-'a'] != root) {
            tmp = d_parent[node-'a'];
            d_parent[node-'a'] = root;
            node = tmp;
        }
        return root;
    }
    
    void join(char a, char b) {
        char r_a = find(a);
        char r_b = find(b);
        if (r_a == r_b) {
            return;
        }
        d_parent[r_a-'a'] = r_b;
    }
    
    bool equationsPossible(vector<string>& equations) {
        d_parent = vector<char>(26, 'a');
        for (int i = 1; i < 26; ++i) {
            d_parent[i] = 'a'+i;
        }
        vector<pair<char, char>> neq;
        for (auto s:equations) {
            if ('!' == s[1]) {
                neq.push_back(pair<int, int>(s[0], s[3]));
            } else {
                join(s[0], s[3]);
            }
        }
        for (auto p:neq) {
            if (find(p.first) == find(p.second)) {
                return false;
            }
        }
        return true;
    }
private:
    vector<char> d_parent;
};
