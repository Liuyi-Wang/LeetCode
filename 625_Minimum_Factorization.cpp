class Solution {
public:
    int smallestFactorization(int a) {
        if (1 == a) {
            return 1;
        }
        long long result = 0;
        long long ten = 1;
        for (long long i = 9; i >= 2; --i) {
            while (a%i == 0) {
                if (result+ten*i > INT_MAX) {
                    return 0;
                }
                result += ten*i;
                ten *= 10;
                a /= i;
            }
        }
        if (1 != a) {
            return 0;
        }
        return result;
    }
};
