static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int result = INT_MAX;
        int index = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i] || word2 == words[i]) {
                if (index != -1 && (words[index] != words[i] || word1 == word2)) {
                    result = min(result, i-index);
                }
                index = i;
            } 
        }
        return result;
    }
};
