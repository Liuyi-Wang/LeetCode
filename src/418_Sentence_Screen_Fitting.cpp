static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> start(sentence.size(), 0);
        vector<int> lens(sentence.size(), 0);
        vector<int> sentences(sentence.size(), 0);
        for (int i = 0; i < sentence.size(); ++i) {
            int col = 0;
            int cur = i;
            int times = 0;
            if (0 != i) {
                col = lens[i-1]-sentence[i-1].size()-1;
                cur = start[i-1];
                times = sentences[i-1];
            }
            while (col+sentence[cur].size() <= cols) {
                col += sentence[cur].size()+1;
                if (cur == sentence.size()-1) {
                    ++times;
                    cur = 0;
                } else {
                    ++cur;
                }
            }
            start[i] = cur;
            sentences[i] = times;
            lens[i] = col;
        }
        int result = 0;
        int cur = 0;
        for (int i = 0; i < rows; ++i) {
            result += sentences[cur];
            cur = start[cur];
        }
        return result;
    }
};
