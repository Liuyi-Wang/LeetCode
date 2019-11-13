class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (1 == num) {
            return false;
        }
        int u = sqrt(num);
        int sum = 1;
        int i = 2;
        while (i <= u) {
            if (num%i == 0) {
                sum += i;
                if (num/i != i) {
                    sum += num/i;
                }
            }
            ++i;
        }
        return sum == num;
    }
};
