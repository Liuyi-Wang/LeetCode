class Solution {
public:
    char solve(char c, int i) {
        if ('a' == c) {
            switch(i) {
                case 0:
                    return 'b';
                case 1:
                    return 'c';
            }
        } else if ('b' == c) {
            switch(i) {
                case 0:
                    return 'a';
                case 1:
                    return 'c';
            }
        } else if ('c' == c) {
            switch(i) {
                case 0:
                    return 'a';
                case 1:
                    return 'b';
            }
        }
        return 'w';
    }
    
    string getHappyString(int n, int k) {
        if (k > 3*pow(2, n-1)) {
            return "";
        }
        --k;
        string result;
        int t = pow(2, n-1);
        int c = k/t;
        int m = k%t;
        if (0 == c) {
            result.push_back('a');
        } else if (1 == c) {
            result.push_back('b');
        } else if (2 == c) {
            result.push_back('c');
        }
        --n;
        k = m;
        while (n > 0) {
            t = pow(2, n-1);
            c = k/t;
            m = k%t;
            result.push_back(solve(result.back(), c));
            k = m;
            --n;
        }
        return result;
    }
};
