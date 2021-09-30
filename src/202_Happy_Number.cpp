class Solution {
public:
    int next(int n) {
        int result = 0;
        while (0 < n) {
            int t = n%10;
            result += t*t;
            n /= 10;
        }
        return result;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(fast);
            fast = next(fast);
        }
        return slow == 1;
    }
};
