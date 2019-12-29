static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> count;
        priority_queue<int> q;
        for (int i = 0; i < A.size(); ++i) {
            ++count[A[i]];
            if (1 == count[A[i]]) {
                q.push(A[i]);
            }
            while (!q.empty() && 1 != count[q.top()]) {
                q.pop();
            }
        }
        return q.empty()?(-1):q.top();
    }
};
