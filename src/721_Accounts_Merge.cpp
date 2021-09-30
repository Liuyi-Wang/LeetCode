class Solution {
public:
    string f(string s) {
        string r = s;
        while (r != d_root[r]) {
            r = d_root[r];
        }
        while (d_root[s] != r) {
            string t = d_root[s];
            d_root[s] = r;
            s = t;
        }
        return r;
    }
    
    void u(const string& s1, const string& s2) {
        string r1 = f(s1);
        string r2 = f(s2);
        if (r1 != r2) {
            d_root[r2] = r1;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); ++i) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                d_name[email] = name;
                d_root[email] = email;
            }
            
        }
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 2; j < accounts[i].size(); ++j) {
                u(accounts[i][1], accounts[i][j]);            
            }
        }
        unordered_map<string, set<string>> groups;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                groups[f(email)].insert(email);
            }
        }
        vector<vector<string>> result;
        for (unordered_map<string, set<string>>::iterator it = groups.begin(); it != groups.end(); ++it) {
            vector<string> account(1, d_name[it->first]);
            vector<string> emails(it->second.begin(), it->second.end());
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        return result;
    }
private:
    unordered_map<string, string> d_root;
    unordered_map<string, string> d_name;
};
