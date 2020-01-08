static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (d_hash.find(input) != d_hash.end()) {
            return d_hash[input];
        }
        if (0 == input.size()) {
            d_hash[input] = vector<int>();
            return vector<int>();
        }
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if ('+' == input[i] || '-' == input[i] || '*' == input[i]) {
                vector<int> l = diffWaysToCompute(input.substr(0, i));
                vector<int> r = diffWaysToCompute(input.substr(i+1));
                for (int j = 0; j < l.size(); ++j) {
                    for (int k = 0; k < r.size(); ++k) {
                        if ('+' == input[i]) {
                            result.push_back(l[j]+r[k]);
                        } else if ('-' == input[i]) {
                            result.push_back(l[j]-r[k]);
                        } else if ('*' == input[i]) {
                            result.push_back(l[j]*r[k]);
                        }
                    }
                }
            }
        }
        if (0 == result.size()) {
            result.push_back(atoi(input.c_str()));
        }
        d_hash[input] = result;
        return result;
    }
    
private:
    unordered_map<string, vector<int>> d_hash;
};
