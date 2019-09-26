class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            string t = a;
            a = b;
            b = t;
        }
        int carry = 0;
        int sum = 0;
        int ia = a.size()-1, ib = b.size()-1;
        while (0 <= ia && 0 <= ib) {
            sum = carry + (a[ia--]-'0') + (b[ib--]-'0');
            a[ia+1] = (sum%2+'0');
            carry = sum/2;
        }
        while (0 <= ia) {
            sum = carry + (a[ia--]-'0');
            a[ia+1] = (sum%2+'0');
            carry = sum/2;
        }
        if (1 == carry) {
            return "1"+a;
        }
        return a;
    }
};
