static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size()-2; i >= 0; --i) {
            shifts[i] += shifts[i+1]%26;
        }
        for (int i = 0; i < shifts.size(); ++i) {
            S[i] = 'a'+(S[i]-'a'+shifts[i])%26;
        }
        return S;
    }
};
