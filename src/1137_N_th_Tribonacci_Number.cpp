class Solution {
public:
    int tribonacci(int n) {
        if (0 == n) {
            return 0;
        }
        if (1 == n) {
            return 1;
        }
        if (2 == n) {
            return 1;
        }
        vector<int> ns(38, 0);
        ns[0] = 0;
        ns[1] = 1;
        ns[2] = 1;
        for (int i = 3; i <= n; ++i) {
            ns[i] = ns[i-1]+ns[i-2]+ns[i-3];
        }
        return ns[n];
    }
};
