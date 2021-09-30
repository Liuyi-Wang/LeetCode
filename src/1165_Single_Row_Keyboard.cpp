static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> hash(26, 0);
        for (int i = 0; i < keyboard.size(); ++i) {
            hash[keyboard[i]-'a'] = i;
        }
        int result = hash[word[0]-'a'];
        for (int i = 1; i < word.size(); ++i) {
            result += abs(hash[word[i]-'a']-hash[word[i-1]-'a']);
        }
        return result;
    }
};
