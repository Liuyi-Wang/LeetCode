class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for (int i = 0; i < S.size(); ++i) {
            if ('(' == S[i]) {
                s.push(0);
            } else {
                int sum = 0;
                while (!s.empty()) {
                    int n = s.top();
                    s.pop();
                    if (0 == n) {
                        break;
                    } else {
                        sum += n;
                    }
                }
                if (0 == sum) {
                    s.push(1);
                } else {
                    s.push(sum*2);
                }
            }
        }
        int result = 0;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        return result;
    }
};
