class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        int i = -1;
        for (int j = 0; j < n.size(); ++j) {
            if ('9' != n[j]) {
                i = j;
                break;
            }
        }
        int a = num;
        if (-1 != i) {
            char c = n[i];
            for (int j = 0; j < n.size(); ++j) {
                if (c == n[j]) {
                    n[j] = '9';
                }
            }
            a = atoi(n.c_str());
        }
        int b = num;
        n = to_string(num);
        if ('1' != n[0]) {
            char c = n[0];
            for (int j = 0; j < n.size(); ++j) {
                if (c == n[j]) {
                    n[j] = '1';
                }
            }
            b = atoi(n.c_str());
        } else {
            i = -1;
            for (int j = 1; j < n.size(); ++j) {
                if ('0' != n[j] && '1' != n[j]) {
                    i = j;
                    break;
                }
            }
            if (-1 != i) {
                char c = n[i];
                for (int j = 0; j < n.size(); ++j) {
                    if (c == n[j]) {
                        n[j] = '0';
                    }
                }
                b = atoi(n.c_str());
            }
        }
        return a-b;
    }
};
