class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (auto c:s) {
            if (stk.empty()) {
                stk.push({c, 1});
            } else {
                if (stk.top().first == c && stk.top().second == k-1) {
                    stk.pop();
                } else if (stk.top().first == c) {
                    ++stk.top().second;
                } else {
                    stk.push({c, 1});
                }
            }
        }
        string result;
        while (!stk.empty()) {
            result += string(stk.top().second, stk.top().first);
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
