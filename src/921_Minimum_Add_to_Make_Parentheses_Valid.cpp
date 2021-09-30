class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        int result = 0;
        for (const auto s:S) {
            if ('(' == s) {
                stk.push(s);        
            } else {
                if (stk.empty()) {
                    ++result;    
                } else {
                    stk.pop();
                }
            }
        }
        return result+stk.size();
    }
};
