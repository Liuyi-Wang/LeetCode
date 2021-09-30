static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> counts(26, 0);
        for (const auto &c:s) {
            ++counts[c-'a'];
        }
        vector<int> v(26, false);
        stack<char> stk;
        for (const auto &c:s) {
            --counts[c-'a'];
            if (stk.empty()) {
                v[c-'a'] = true;
                stk.push(c);
            } else if (v[c-'a']) {
                continue;
            } else {
                while (!stk.empty() && stk.top() > c && counts[stk.top()-'a'] > 0) {
                    v[stk.top()-'a'] = false;
                    stk.pop();
                }
                v[c-'a'] = true;
                stk.push(c);
            }
        }
        string result;
        while (!stk.empty()) {
            result = stk.top()+result;
            stk.pop();
        }
        return result;
    }
};
