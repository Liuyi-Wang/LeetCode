class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int square = i*i+j*j;
                int k = sqrt(square);
                if (k <= n && k*k == square) {
                    ++result;
                }
            }
        }
        return result;
    }
};
