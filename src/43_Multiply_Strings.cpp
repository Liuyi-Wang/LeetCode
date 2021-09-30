static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size()+num2.size(), '0');
        int i = result.size()-1;
        for (int i1 = num1.size()-1; i1 >= 0; --i1) {
            int digit = 0;
            int d = 0;
            int index = i;
            for (int i2 = num2.size()-1; i2 >= 0; --i2) {
                int sum = digit+(num1[i1]-'0')*(num2[i2]-'0');
                digit = sum/10;
                int s = result[index]-'0'+sum%10+d;
                result[index] = '0'+s%10;
                d = s/10;
                --index;
            }
            if (digit > 0) {
                int s = result[index]-'0'+digit+d;
                result[index] = '0'+s%10;
                d = s/10;
                --index;
            }
            while (d > 0) {
                int s = result[index]-'0'+d;
                result[index] = '0'+s%10;
                d = s/10;
                --index;
            }
            --i;
        }
        i = 0;
        while ('0' == result[i]) {
            ++i;
        }
        if (i == result.size()) {
            return "0";
        }
        return result.substr(i, result.size()-i);
    }
};
