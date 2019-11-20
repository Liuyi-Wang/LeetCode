static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        s.push(0);
        int result = 0;
        for (int i = 1; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] <= height[i]) {
                int t = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                result += (min(height[i], height[s.top()])-height[t])*(i-s.top()-1);
            }
            s.push(i);
        }
        return result;
    }
};
