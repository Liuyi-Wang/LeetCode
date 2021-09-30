class Solution {
public:
    int findComplement(int num) {
        bool leading = true;
        for (int i = 31; i >= 0; --i) {
            if ((num>>i) == 0 && leading) {
                continue;
            }
            leading = false;
            num ^= (1<<i);
        }
        return num;
    }
};
