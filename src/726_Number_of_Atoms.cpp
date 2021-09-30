static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const string& formula, int begin, int end, int m) {
        if (begin > end) {
            return;
        }
        if (formula[begin] != '(') {
            int l = begin;
            int r = l+1;
            while(r <= end) {
                if (!islower(formula[r])) {
                    break;
                }
                ++r;
            }
            string atom = formula.substr(l, r-l);
            if (r > end) {
                counts[atom] += m;
                return;
            }
            if (!isdigit(formula[r])) {
                counts[atom] += m;
                solve(formula, r, end, m);
                return;
            }
            int ld = r++;
            while (r <= end) {
                if (!isdigit(formula[r])) {
                    break;
                }
                ++r;
            }
            int rd = r-1;
            string count = formula.substr(ld, rd-ld+1);
            counts[atom] += atoi(count.c_str())*m;
            solve(formula, r, end, m);
        } else {
            int p = 1;
            int r = begin+1;
            int lp = begin+1;
            while (r <= end) {
                if (formula[r] == '(') {
                    ++p;
                } else if (formula[r] == ')') {
                    --p;
                }
                if (0 == p) {
                    break;
                }
                ++r;
            }
            int rp = r-1;
            int ld = ++r;
            while (r <= end) {
                if (!isdigit(formula[r])) {
                    break;
                }
                ++r;
            }
            int rd = r-1;
            string count = formula.substr(ld, rd-ld+1);
            solve(formula, lp, rp, atoi(count.c_str())*m);
            solve(formula, r, end, m);
        }
    }
    
    string countOfAtoms(string formula) {
        solve(formula, 0, formula.size()-1, 1);
        string result;
        for (auto p:counts) {
            if (1 == p.second) {
                result += p.first;
            } else {
                result += p.first;
                result += to_string(p.second);
            }
        }
        return result;
    }
    
private:
    map<string, int> counts;
};
