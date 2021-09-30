class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> lr = A;
        vector<int> rl = A;
        int a = A[0];
        for (int i = 0; i < A.size(); ++i) {
            a = max(a, A[i]);
            lr[i] = a;
        }
        a = A.back();
        for (int i = A.size()-1; i >= 0; --i) {
            rl[i] = a;
            a = min(a, A[i]);
        }
        for (int i = 0; i < A.size(); ++i) {
            if (lr[i] <= rl[i]) {
                return i+1;
            }
        }
        return 0;
    }
};
