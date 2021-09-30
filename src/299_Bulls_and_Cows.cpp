static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> ac(10, 0);
        vector<int> gc(10, 0);
        int a = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++a;
            } else {
                ++ac[secret[i]-'0'];
                ++gc[guess[i]-'0'];
            }
        }
        int b = 0;
        for (int i = 0; i < 10; ++i) {
            b += min(ac[i], gc[i]);
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
