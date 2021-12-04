class Solution {
public:
    int find(int a) {
        int r = a;
        while (d_r[r] != r) {
            r = d_r[r];
        }
        while (d_r[a] != r) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra < rb) {
            d_r[rb] = ra;
        } else {
            d_r[ra] = rb;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        d_r = vector<int>(accounts.size(), 0);
        for (int i = 0; i < accounts.size(); ++i) {
            d_r[i] = i;
        }
        vector<string> names(accounts.size(), "");
        
        for (int i = 0; i < accounts.size(); ++i) {
            names[i] = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (email2id.find(accounts[i][j]) == email2id.end()) {
                    email2id[accounts[i][j]] = i;
                } else {
                    merge(email2id[accounts[i][j]], i);
                    email2id[accounts[i][j]] = find(i);
                }
            }
        }
        unordered_map<int, vector<string>> hash;
        vector<vector<string>> result;
        for (unordered_map<string, int>::iterator it = email2id.begin(); it != email2id.end(); ++it) {
            hash[find(it->second)].push_back(it->first);
        }
        for (unordered_map<int, vector<string>>::iterator it = hash.begin(); it != hash.end(); ++it) {
            result.push_back(it->second);
            sort(result.back().begin(), result.back().end());
            result.back().insert(result.back().begin(), names[it->first]);
        }
        return result;
    }

private:
    vector<int> d_r;
    unordered_map<string, int> email2id;
};
