static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int read = 0;
        while (true) {
            int r = read4(buf+read);
            read += r;
            if (read >= n) {
                return n;
            }
            if (r < 4) {
                return read;
            }
        }
        return n;
    }
};
