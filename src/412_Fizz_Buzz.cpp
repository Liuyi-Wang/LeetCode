static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            if (0 == i%3 && 0 == i%5) {
                result.push_back("FizzBuzz");
            } else if (0 == i%3) {
                result.push_back("Fizz");
            } else if (0 == i%5) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};
