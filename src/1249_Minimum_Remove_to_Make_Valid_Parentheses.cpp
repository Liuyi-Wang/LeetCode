class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> rm;
        stack<int> p;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                p.push(i);
            } else if (s[i] == ')') {
                if (p.empty()) {
                    rm.insert(i);
                } else {
                    p.pop();
                }
            }
        }
        while (!p.empty()) {
            rm.insert(p.top());
            p.pop();
        }
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (rm.find(i) != rm.end()) {
                continue;
            }
            result += s[i];
        }
        return result;
    }
};
