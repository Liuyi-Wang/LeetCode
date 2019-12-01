static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int result = 0;
        stack<int> stk;
        stack<int> r;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int begin = i;
                ++i;
                while (i < s.size() && isdigit(s[i])) {
                    ++i;
                }
                result += sign*atoi(s.substr(begin, i-begin).c_str());
                --i;
            } else if ('+' == s[i]) {
                sign = 1;
            } else if ('-' == s[i]) {
                sign = -1;
            } else if ('(' == s[i]) {
                stk.push(sign);
                r.push(result);
                sign = 1;
                result = 0;
            } else if (')' == s[i]) {
                result = stk.top()*(result)+r.top();
                stk.pop();
                r.pop();
            }
        }
        return result;
    }
};
