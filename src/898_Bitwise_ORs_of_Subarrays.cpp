static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if (A.size() < 2) {
            return A.size();
        }
        vector<int> v;
        int begin = 0, end = 0;
        for (int i = 0; i < A.size(); ++i) {
            v.push_back(A[i]);
            while (begin < end) {
                int t = A[i] | v[begin];
                if (v.back() != t) {
                    v.push_back(t);
                }
                ++begin;
            }
            end = v.size();
        }
        return unordered_set<int>(v.begin(), v.end()).size();
    }
};
