static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (words.size() < j+1 || words[j].size() < i+1 || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
