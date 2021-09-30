static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ap = a.find_first_of('+');
        int ar = atoi(a.substr(0, ap).c_str());
        int ai = atoi(a.substr(ap+1, a.size()-1-ap).c_str());
        int bp = b.find_first_of('+');
        int br = atoi(b.substr(0, bp).c_str());
        int bi = atoi(b.substr(bp+1, b.size()-1-bp).c_str());
        int r = ar*br-ai*bi;
        int i = ar*bi+ai*br;
        return to_string(r)+"+"+to_string(i)+"i";
    }
};
