static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string intToRoman(int num) {
        string result;
        while (num > 0) {
            if (num >= 1000) {
                int n = num/1000;
                num %= 1000;
                result += string(n, 'M');
            } else if (num >= 900) {
                num -= 900;
                result += "CM";
            } else if (num >= 500) {
                int n = num/500;
                num %= 500;
                result += string(n, 'D');
            } else if (num >= 400) {
                num -= 400;
                result += "CD";
            } else if (num >= 100) {
                int n = num/100;
                num %= 100;
                result += string(n, 'C');
            } else if (num >= 90) {
                num -= 90;
                result += "XC";
            } else if (num >= 50) {
                int n = num/50;
                num %= 50;
                result += string(n, 'L');
            } else if (num >= 40) {
                num -= 40;
                result += "XL";
            } else if (num >= 10) {
                int n = num/10;
                num %= 10;
                result += string(n, 'X');
            } else if (num >= 9) {
                num -= 9;
                result += "IX";
            } else if (num >= 5) {
                int n = num/5;
                num %= 5;
                result += string(n, 'V');
            } else if (num >= 4) {
                num -= 4;
                result += "IV";
            } else {
                result += string(num, 'I');
                num = 0;
            }
        }
        return result;
    }
};
