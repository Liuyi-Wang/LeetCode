class Solution {
public:
    int bitwiseComplement(int N) {
        int result = 2;
        while (result <= N) {
            result *= 2;
        }
        return result-1-N;
    }
};
