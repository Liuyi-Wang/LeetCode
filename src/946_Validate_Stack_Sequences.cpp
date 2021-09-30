static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1, s2;
        for (int i = popped.size()-1; i >= 0; --i) {
            s2.push(popped[i]);
        } 
        for (int i = 0; i < pushed.size(); ++i) {
            s1.push(pushed[i]);
            while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
                s1.pop();
                s2.pop();
            }
        }
        return s1.empty() && s2.empty();
    }
};
