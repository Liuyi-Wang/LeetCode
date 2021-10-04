class Solution {
public:
    int minOperations(int n) {
        if (n%2 == 0) {
            return (1+n-1)*((n+1)/2)/2;
        } else {
            return (0+n-1)*((n+1)/2)/2;
        }
    }
};
