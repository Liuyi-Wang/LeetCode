class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool east = true, up = true;
        int e = 0, w = 0;
        while (true) {
            if (east) {
                if (up) {
                    e = w+q;
                    if (p == e) {
                        return 1;
                    }
                    if (p < e) {
                        e = 2*p-e;
                        up = false;
                    }
                } else {
                    e = w-q;   
                    if (0 == e) {
                        return 0;
                    }
                    if (0 > e) {
                        e = -e;
                        up = true;
                    }
                }
                east = false;
            } else {
                if (up) {
                    w = e+q;
                    if (p == w) {
                        return 2;
                    }
                    if (p < w) {
                        w = 2*p-w;
                        up = false;
                    }
                } else {
                    w = e-q;   
                    if (0 > w) {
                        w = -w;
                        up = true;
                    }
                }
                east = true;
            }
        }
        return -1;
    }
};
