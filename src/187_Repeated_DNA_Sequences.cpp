static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int toInt(char c) {
        if ('A' == c) {
            return 0;
        }    
        if ('C' == c) {
            return 1;
        }
        if ('G' == c) {
            return 2;
        }
        if ('T' == c) {
            return 3;
        }
        return -1;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        int mask = 0xfffff;
        unordered_map<int, int> counts;
        vector<string> result;
        int n = 0;
        if (s.size() < 10) {
            return result;
        }
        for (int i = 0; i < 9; ++i) {
            n = (n<<2)|toInt(s[i]); 
        }
        for (int i = 9; i < s.size(); ++i) {
            n = mask&((n<<2)|toInt(s[i]));
            ++counts[n];
            if (2 == counts[n]) {
                result.push_back(s.substr(i-9, 10));
            }
        }
        return result;
    }
};
