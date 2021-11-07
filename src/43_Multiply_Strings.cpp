/**
 *  Time:
 *  O(M*N) to multiply
 *  O(M*(M+N)) to add all
 *  Space:
 *  O(M*(M+N))
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<string> nums;
        int shift = 0;
        for (int i = 0; i < num1.size(); ++i) {
            string s(shift, '0');
            int carry = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int sum = (num1[i]-'0')*(num2[j]-'0') + carry;
                s += to_string(sum%10);
                carry = sum/10;
            }
            if (carry) {
                s += to_string(carry);
            }
            nums.push_back(s);
            ++shift;
        }
        string result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result = add(result, nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    string add(const string& s1, const string& s2) {
        int i1 = 0, i2 = 0;
        int carry = 0;
        string result;
        while (i1 < s1.size() && i2 < s2.size()) {
            int sum = (s1[i1]-'0') + (s2[i2]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            ++i1;
            ++i2;
        }
        while (i1 < s1.size()) {
            int sum = (s1[i1]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            ++i1;
        }
        while (i2 < s2.size()) {
            int sum = (s2[i2]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            ++i2;
        }
        if (carry) {
            result += to_string(carry);
        }
        return result;
    }
};
