static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string solve(const vector<int> &v) {
        if (2 == v.size()) {
            return "("+to_string(v[0])+","+to_string(v[1])+")";
        }
        vector<int> l = {v[0]};
        vector<int> r;
        for (int i = 1; i < v.size()-1;) {
            if (1 == i%4) {
                r.push_back(v[i]);
                r.push_back(v[i+1]);
            } else {
                l.push_back(v[i]);
                l.push_back(v[i+1]);
            }
            i += 2;
        }
        l.push_back(v.back());
        string lm = solve(l);
        string rm = solve(r);
        return "("+lm+","+rm+")";
    }
    
    string findContestMatch(int n) {
        /*
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        return solve(v);*/
        vector<string> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(to_string(i));
        }
        while (n > 1) {
            for (int i = 0; i < n/2; ++i) {
                v[i] = "("+v[i]+","+v[n-i-1]+")";
            }
            n /= 2;
        }
        return v[0];
    }
};
