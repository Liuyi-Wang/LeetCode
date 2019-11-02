static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for (const auto &s:strs) {
            result += to_string(s.size())+"#"+s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int begin = 0;
        int i = s.find('#');
        vector<string> result;
        while (string::npos != i) {
            int len = atoi(s.substr(begin, i-begin).c_str());
            result.push_back(s.substr(i+1, len));
            begin = i+len+1;
            i = s.find('#', i+1+len);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
