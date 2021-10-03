class Solution {
public:
    int minPartitions(string n) {
        char c = '0';
        for (auto digit:n) {
            c = max(c, digit);
        }
        return c-'0';
    }
};
