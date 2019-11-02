static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class StringIterator {
public:
    StringIterator(string compressedString) {
        d_s = compressedString;
        d_i = 0;
        d_c = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (d_c > 0) {
            --d_c;
            return d_char;
        }
        d_char = d_s[d_i++];
        int begin = d_i;
        for (; d_i < d_s.size(); ++d_i) {
            if (!isdigit(d_s[d_i])) {
                break;
            }
        }
        d_c = atoi(d_s.substr(begin, d_i-begin).c_str())-1;
        return d_char;
    }
    
    bool hasNext() {
        if (d_i == d_s.size() && 0 == d_c) {
            return false;
        }
        return true;
    }
    
private:
    string d_s;
    char d_char;
    int d_i;
    int d_c;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
