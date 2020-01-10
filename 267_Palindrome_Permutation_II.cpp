class Solution {
public:
    void solve(bool odd, string s, char c, int i) {
        if (i == s.size()) {
            string t = s;
            reverse(t.begin(), t.end());
            if (odd) {
                d_result.push_back(s+c+t);   
            } else {
                d_result.push_back(s+t);
            }
            return;
        }
        solve(odd, s, c, i+1);
        for (int j = i+1; j < s.size(); ++j) {
            if (s[i] == s[j]) {
                continue;
            }
            swap(s[i], s[j]);
            solve(odd, s, c, i+1);
            //swap(s[i], s[j]);
        }
    }
    
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> counts;
        int odd = 0, even = 0;
        for (auto c:s) {
            ++counts[c];
            if (1 == counts[c]) {
                ++odd;
            } else if (0 == counts[c]%2) {
                --odd;
                ++even;
            } else {
                --even;
                ++odd;
            }
        }
        vector<string> result;
        if (odd > 1) {
            return d_result;
        }
        if (0 == odd) {
            string half;
            for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
                half += string((it->second)/2, it->first);
            }
            solve(false, half, '?', 0);
        } else {
            string half;
            char c;
            for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
                if (1 == (it->second)%2) {
                    c = it->first;
                }
                half += string((it->second)/2, it->first);
            }
            solve(true, half, c, 0);
        }
        return d_result;
    }
    
private:
    vector<string> d_result;
};
