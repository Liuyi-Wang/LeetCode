static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0;
        int count = 1;
        int index = 0;
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == chars[i-1]) {
                ++count;
            } else {
                if (1 == count) {
                    chars[index++] = chars[i-1];
                    ++result;
                } else {
                    chars[index++] = chars[i-1];
                    ++result;
                    string n;
                    while (count > 0) {
                        n += to_string(count%10);
                        count /= 10;
                        ++result;
                    }
                    for (int j = n.size()-1; j >= 0; --j) {
                        chars[index++] = n[j];
                    }
                }
                count = 1;
            }
        }
        if (1 == count) {
            chars[index++] = chars[chars.size()-1];
            ++result;
        } else {
            chars[index++] = chars[chars.size()-1];
            ++result;
            string n;
            while (count > 0) {
                n += to_string(count%10);
                count /= 10;
                ++result;
            }
            for (int j = n.size()-1; j >= 0; --j) {
                chars[index++] = n[j];
            }
        }
        return result;
    }
};
