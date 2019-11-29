static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct greater_than {
        inline bool operator() (const string &s1, const string &s2) {
            return s1+s2>s2+s1;
        }       
    };

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto num:nums) {
            v.push_back(to_string(num));
        }
        sort(v.begin(), v.end(), greater_than());
        string result;
        for (int i = 0; i < nums.size(); ++i) {
            result += v[i];
        }
        if ('0' == result[0]) {
            return "0";
        }
        return result;
    }
};
