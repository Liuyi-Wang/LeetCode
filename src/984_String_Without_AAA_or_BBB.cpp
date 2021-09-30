class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char a = 'a';
        char b = 'b';
        if (A < B) {
            int temp = A;
            A = B;
            B = temp;
            a = 'b';
            b = 'a';
        }
        string result(A+B, a);
        if (A/2 >= B) {
            int index = 2;
            while (index < A+B) {
                result[index] = b;
                index += 3;
            }
            return result;
        }
        int two = A%B;
        int t = 0;
        int index = -1;
        while (t < two) {
            index += 3;
            result[index] = b;
            ++t;
        }
        index += 2;
        while (index < A+B) {
            result[index] = b;
            index += 2;
        }
        return result;
    }
};
