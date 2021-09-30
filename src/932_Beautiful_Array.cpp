static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(vector<int>& v, int begin, int end) {
        if (begin == end) {
            return;
        }
        int mid = begin+(end-begin)/2;
        vector<int> copy = v;
        for (int i = begin+1, j = begin+2; i <= mid; ++i, j += 2) {
            v[i] = copy[j];
        }
        for (int i = mid+1, j = begin+1; i <= end; ++i, j += 2) {
            v[i] = copy[j];
        }
        solve(v, begin, mid);
        solve(v, mid+1, end);
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> result(N, 1);
        for (int i = 1; i < N; ++i) {
            result[i] = i+1;
        }
        solve(result, 0, N-1);
        return result;
    }
};
