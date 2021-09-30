class Solution {
public:
    string addStrings(string num1, string num2) {
        int i1 = num1.size()-1, i2 = num2.size()-1;
        int digit = 0;
        string result;
        while (i1 >= 0 && i2 >= 0) {
            int sum = digit + (num1[i1--]-'0')+(num2[i2--]-'0');
            digit = sum/10;
            result += (sum%10)+'0';
        }
        while (i1 >= 0) {
            int sum = digit + (num1[i1--]-'0');
            digit = sum/10;
            result += (sum%10)+'0';
        }
        while (i2 >= 0) {
            int sum = digit + (num2[i2--]-'0');
            digit = sum/10;
            result += (sum%10)+'0';
        }
        if (digit > 0) {
            result += digit+'0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
