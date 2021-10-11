class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        int i = 0;
        while ((left>>i) != 0 && (right>>i) != 0) {
            if ((left>>i) == (right>>i)) {
                result = max(result, ((left>>i)<<i));
            }
            ++i;
        }
        return result;
    }
};
