class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long r = 0;
        int X = x;
        while (X > 0) {
            r = r*10+X%10;
            X /= 10;
        }
        return x == r;
    }
};
