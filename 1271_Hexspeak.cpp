static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toHexspeak(string num) {
        string result;
        long n = atol(num.c_str());
        while (n > 0) {
            int d = n%16;
            if (d <= 9 && (d != 0 && d != 1)) {
                return "ERROR";
            }
            if (0 == d) {
                result = "O"+result; 
            } else if (1 == d) {
                result = "I"+result; 
            } else {
                char c = 'A'+d-10;
                result = c+result;
            }
            n /= 16;
        }
        return result;
    }
};
