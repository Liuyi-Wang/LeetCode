class Solution {
public:
    string convertToBase7(int num) {
        if (0 == num) {
            return "0";
        }
        bool pos = num>=0;
        num = abs(num);
        string result;
        while (num > 0) {
            result = to_string(num%7)+result;
            num /= 7;
        }
        return (!pos?"-":"")+result;
    }
};
