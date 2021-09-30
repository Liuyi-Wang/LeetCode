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
        if (i > INT_MAX) {
            return false;
        } 
        string n = to_string(i);
        if (begin + n.size() > num.size()) {
            return false;
        }
        if (n != num.substr(begin, n.size())) {
            return false;
        }
        d_result.push_back(atol(n.c_str()));
        return solve(num, n2, n, begin+n.size(), count+1);
    }
    
    vector<int> splitIntoFibonacci(string S) {
        string num = S;
        d_limit = 10;
        for (int i = 0; i < num.size() && i < d_limit; ++i) {
            if ('0' == num[0] && i > 0) {
                break;
            }
            for (int j = i+1; j < num.size(); ++j) {
                if ('0' == num[i+1] && j > i+1) {
                    break;
                }
                if (j-i > d_limit) {
                    break;
                }
                d_result.push_back(atol(num.substr(0, i+1).c_str()));
                d_result.push_back(atol(num.substr(i+1, j-i).c_str()));
                if (solve(num, num.substr(0, i+1), num.substr(i+1, j-i), j+1, 2)) {
                    return d_result;
                }
                d_result.clear();
            }
        }
        return d_result;
    }

private:
    vector<int> d_result;
    int d_limit;
};
