class Solution {
public:
    int clumsy(int N) {
        if (1 == N) {
            return 1;
        }
        if (2 == N) {
            return 2;
        }
        if (3 == N) {
            return 6;
        }
        int result = N*(N-1)/(N-2)+N-3;
        N -= 4;
        while (N >= 4) {
            result = result-N*(N-1)/(N-2)+N-3;
            N -= 4;
        }
        if (1 == N) {
            return result-1;
        }
        if (2 == N) {
            return result-2;
        }
        if (3 == N) {
            return result-6;
        }
        return result;
    }
};
