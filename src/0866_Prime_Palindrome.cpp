class Solution {
public:
    int primePalindrome(int n) {
        if (n <= 2) {
            return 2;
        }
        if (n <= 3) {
            return 3;
        }
        if (n <= 5) {
            return 5;
        }
        if (n <= 7) {
            return 7;
        }
        if (n <= 11) {
            return 11;
        }
        int l = to_string(n).size();
        int low = pow(10, l/2);
        for (int i = low; i <= 20000; ++i) {
            int r = 0;
            int count = 0;
            int j = i;
            while (j > 0) {
                r = r*10+j%10;
                j /= 10;
                ++count;
            }
            j = i/10;
            j = j*pow(10, count)+r;
            if (j < n) {
                continue;
            }
            if (valid(j)) {
                return j;
            }
        }
        return -1;
    }
    
    bool valid(int j) {
        for (int i = 2; i*i <= j; ++i) {
            if (j%i == 0) {
                return false;
            }
        }
        return true;
    }
};
