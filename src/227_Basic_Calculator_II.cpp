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
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int begin = i;
                ++i;
                while (i < s.size() && isdigit(s[i])) {
                    ++i;
                }
                --i;
                stk.push(sign*atoi(s.substr(begin, i-begin+1).c_str()));
            } else if ('+' == s[i]) {
                sign = 1;
            } else if ('-' == s[i]) {
                sign = -1;
            } else if ('*' == s[i]) {
                ++i;
                while (i < s.size() && !isdigit(s[i])) {
                    ++i;
                }
                int begin = i;
                while (i < s.size() && isdigit(s[i])) {
                    ++i;
                }
                --i;
                stk.top() *= atoi(s.substr(begin, i-begin+1).c_str());
            } else if ('/' == s[i]) {
                ++i;
                while (i < s.size() && !isdigit(s[i])) {
                    ++i;
                }
                int begin = i;
                while (i < s.size() && isdigit(s[i])) {
                    ++i;
                }
                --i;
                stk.top() /= atoi(s.substr(begin, i-begin+1).c_str());
            }
        }
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
