static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int b = 0;
        while (b < words.size()) {
            int size = words[b].size();
            int e = b;
            while (e+1 < words.size()) {
                if (size+1+words[e+1].size() <= maxWidth) {
                    size += 1+words[e+1].size();
                    ++e;
                } else {
                    break;
                }
            }
            if (e == words.size()-1) {
                string s = words[b];
                for (int i = b+1; i <= e; ++i) {
                    s += " "+words[i];
                }
                s += string(maxWidth-s.size(), ' ');
                result.push_back(s);
                break;
            }
            if (b == e) {
                string s = words[b] + string(maxWidth-words[b].size(), ' ');
                result.push_back(s);
                b = e+1;
                continue;
            }
            int wordsize = size-(e-b);
            int space = maxWidth-wordsize;
            int n = space/(e-b);
            int m = space%(e-b);
            string s = words[b];
            for (int i = b+1; i <= b+m; ++i) {
                s += string(n+1, ' ')+words[i];
            }
            for (int i = b+m+1; i <= e; ++i) {
                s += string(n, ' ')+words[i];
            }
            result.push_back(s);
            b = e+1;
        }
        return result;
    }
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (e == nums[i]) {
                ++c;
            } else {
                --c;
            }
            if (0 == c) {
                ++i;
                e = nums[i];
                c = 1;
            }
        }
        return e;
    }
};
};
