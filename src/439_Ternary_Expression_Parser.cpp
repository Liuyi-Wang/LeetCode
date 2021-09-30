static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string parseTernary(string expression) {
        if (1 == expression.size()) {
            return expression;
        }
        int q = -1;
        for (int i = 0; i < expression.size(); ++i) {
            if ('?' == expression[i]) {
                q = i;
                break;
            }
        }
        int o = -1;
        int count = 1;
        for (int i = q+1; i < expression.size(); ++i) {
            if ('?' == expression[i]) {
                ++count;
            } else if (':' == expression[i]) {
                --count;
            }
            if (0 == count) {
                o = i;
                break;
            }
        }
        if ('T' == expression[0]) {
            return parseTernary(expression.substr(q+1, o-1-q));
        }
        if ('F' == expression[0]) {
            return parseTernary(expression.substr(o+1));
        }
        return expression;
    }
};
