class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = A[0], b = B[0];
        int count = 0, equal = 0;
        if (A[0] == B[0]) {
            ++equal;
        }
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == B[i]) {
                ++equal;
            }
            if (a == A[i] && b == B[i]) {
                continue;
            }
            if (a == A[i] && b != B[i]) {
                b = 0;
                continue;
            }
            if (a != A[i] && b == B[i]) {
                a = 0;
                continue;
            }
            if (a != A[i] && b != B[i]) {
                if (a == B[i] && b == A[i]) {
                    ++count;
                } else if (a == B[i] && b != A[i]) {
                    ++count;
                    b = 0;
                } else if (a != B[i] && b == A[i]) {
                    ++count;
                    a = 0;
                } else {
                    return -1;
                }
            }
        }
        return min(count, int(A.size())-count-equal);
    }
};
