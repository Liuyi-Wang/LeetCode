static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (const auto &w:wordList) {
            dict.insert(w);
        }
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        queue<string> q;
        unordered_map<string, int> len;
        q.push(beginWord);
        len[beginWord] = 1;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            int l = len[s];
            for (int i = 0; i < s.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    if ('a'+j == s[i]) {
                        continue;
                    }
                    string t = s;
                    t[i] = 'a'+j;
                    if (endWord == t) {
                        return l+1;
                    }
                    if (dict.find(t) == dict.end() || len.find(t) != len.end()) {
                        continue;
                    }
                    q.push(t);
                    len[t] = l+1;
                }
            }
        }
        return 0;
    }
};
