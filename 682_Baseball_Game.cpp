static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int sum = 0;
        for (const auto& s:ops) {
            if ("+" == s) {
                int last1 = stk.top();
                stk.pop();
                int next = last1+stk.top();
                sum += next;
                stk.push(last1);
                stk.push(next);
            } else if ("D" == s) {
                sum += stk.top()*2;
                stk.push(stk.top()*2);
            } else if ("C" == s) {
                sum -= stk.top();
                stk.pop();
            } else {
                sum += atoi(s.c_str());
                stk.push(atoi(s.c_str()));
            }
        }
        return sum;
    }
};
