class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (const auto& c:s) {
            if ('(' == c || '{' == c || '[' == c) {
                stk.push(c);
            } else if (')' == c && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if ('}' == c && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (']' == c && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty()?true:false;
    }
};
