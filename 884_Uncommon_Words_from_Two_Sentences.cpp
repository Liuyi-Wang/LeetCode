static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream sa(A);
        unordered_map<string, int> ca;
        string t;
        while (sa >> t) {
            ++ca[t];
        }
        stringstream sb(B);
        unordered_map<string, int> cb;
        while (sb >> t) {
            ++cb[t];
        }
        set<string> s;
        stringstream ssa(A);
        while (ssa >> t) {
            if (ca[t] == 1 && cb.find(t) == cb.end()) {
                s.insert(t);
            }
        }
        stringstream ssb(B);
        while (ssb >> t) {
            if (cb[t] == 1 && ca.find(t) == ca.end()) {
                s.insert(t);
            }
        }
        vector<string> result(s.begin(), s.end());
        return result;
    }
};
