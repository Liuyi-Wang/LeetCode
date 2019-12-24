static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(int h, int m, const int start, const int n, const int &num) {
        if (n == num) {
            string hs = to_string(h);
            string ms = to_string(m);
            if (1 == ms.size()) {
                ms = "0"+ms;
            }
            d_result.push_back(hs+":"+ms);
            return;
        }
        for (int i = start; i <= 10-(num-n); ++i) {
            if (i < 4) {
                if (h+(1<<(3-i)) < 12) {
                    solve(h+(1<<(3-i)), m, i+1, n+1, num);
                }
            } else {
                if (m+(1<<(9-i)) < 60) {
                    solve(h, m+(1<<(9-i)), i+1, n+1, num);
                }
            }
        }
    } 
    
    vector<string> readBinaryWatch(int num) {
        solve(0, 0, 0, 0, num);
        return d_result;
    }
    
private:
    vector<string> d_result;
};
