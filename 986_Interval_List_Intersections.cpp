class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> result;
        while (i < A.size() && j < B.size()) {
            int head = max(A[i][0], B[j][0]);
            int tail = min(A[i][1], B[j][1]);
            if (head <= tail) {
                vector<int> interval(2, head);
                interval[1] = tail;
                result.push_back(interval);
            }
            if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
