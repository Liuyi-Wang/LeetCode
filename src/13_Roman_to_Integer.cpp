static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (hash[s[i]] >= hash[s[i+1]]) {
                result += hash[s[i]];
            } else {
                result -= hash[s[i]];
            }
        }
        return result+hash[s.back()];
    }
};
