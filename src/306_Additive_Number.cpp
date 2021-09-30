static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(const string& num, string n1, string n2, int begin, int count) {
        if (begin == num.size()) {
            return count>2?true:false;
        }
        unsigned long long i1 = atol(n1.c_str()), i2 = atol(n2.c_str());
        unsigned long long i = i1+i2;
        string n = to_string(i);
        if (begin + n.size() > num.size()) {
            return false;
        }
        if (n != num.substr(begin, n.size())) {
            return false;
        }
        return solve(num, n2, n, begin+n.size(), count+1);
    }
    
    bool isAdditiveNumber(string num) {
        if ('0' == num[0]) {
            int i = 0;
            if ('0' == num[i+1]) {
                int j = i+1;
                if (solve(num, num.substr(0, i+1), num.substr(i+1, j-i), j+1, 2)) {
                    return true;
                }
            } else {
                for (int j = i+1; j < num.size(); ++j) {
                    if (solve(num, num.substr(0, i+1), num.substr(i+1, j-i), j+1, 2)) {
                        return true;
                    }
                }
            }
        } else {
            for (int i = 0; i < num.size(); ++i) {
                if ('0' == num[i+1]) {
                    int j = i+1;
                    if (solve(num, num.substr(0, i+1), num.substr(i+1, j-i), j+1, 2)) {
                        return true;
                    }
                } else {
                    for (int j = i+1; j < num.size(); ++j) {
                        if (solve(num, num.substr(0, i+1), num.substr(i+1, j-i), j+1, 2)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
