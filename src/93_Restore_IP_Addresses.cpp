class Solution {
public:
    void solve(const string &s, int begin, int n, string address) {
        if (begin == s.size() && 4 == n) {
            d_result.push_back(address.substr(0, address.size()-1));
            return;
        }
        if (n > 4) {
            return;
        }
        if ('0' == s[begin]) {
            solve(s, begin+1, n+1, address+"0.");
            return;
        }
        for (int i = begin; i < s.size(); ++i) {
            int num = atoi(s.substr(begin, i-begin+1).c_str());
            if (num >= 0 && num <= 255) {
                string newAddress = address + s.substr(begin, i-begin+1) + ".";
                solve(s, i+1, n+1, newAddress);
            } else {
                break;
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return d_result;
    }
    
private:
    vector<string> d_result;
};
