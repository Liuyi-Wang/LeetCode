static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s;
        for (auto a:A) {
            s.insert(a);
        }
        vector<int> result;
        for (auto b:B) {
            set<int>::iterator it = s.upper_bound(b);
            if (it != s.end()) {
                result.push_back(*it);
                s.erase(it);
            } else {
                result.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
        return result;
    }
};
