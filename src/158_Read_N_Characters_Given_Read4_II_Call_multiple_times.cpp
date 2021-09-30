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
        int i = 0;
        while (!d_q.empty() && i < n) {
            buf[i++] = d_q.front();
            d_q.pop();
        }
        while (i < n) {
            char buff[4];
            int read = read4(buff);
            if (0 == read) {
                break;
            }
            int j = 0;
            for (; j < read && i < n; ++j) {
                buf[i++] = buff[j];
            }
            for (; j < read; ++j) {
                d_q.push(buff[j]);
            }
        }
        return i;
    }
    
private:
    queue<char> d_q;
};
