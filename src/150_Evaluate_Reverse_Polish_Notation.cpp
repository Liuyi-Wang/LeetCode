static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if ("+" == tokens[i]) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                s.push(n1+n2);
            } else if ("-" == tokens[i]) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                s.push(n1-n2);
            } else if ("*" == tokens[i]) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                s.push(n1*n2);
            } else if ("/" == tokens[i]) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                s.push(n1/n2);
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};
