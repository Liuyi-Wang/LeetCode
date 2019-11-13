class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            int t = i;
            bool valid = true;
            while (0 != t) {
                int r = t%10;
                if (0 == r) {
                    valid = false;
                    break;
                }
                if (0 != i%r) {
                    valid = false;
                    break;
                }
                t /= 10;
            }
            if (valid) {
                result.push_back(i);
            }
        }
        return result;
    }
};
