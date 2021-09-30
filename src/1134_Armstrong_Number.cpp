class Solution {
public:
    bool isArmstrong(int N) {
        int n = N;
        int k = 0;
        while (N > 0) {
            N /= 10;
            ++k;
        }
        int sum = 0;
        N = n;
        while (N > 0) {
            sum += pow(N%10, k);
            N /= 10;
        }
        return n == sum;
    }
};
