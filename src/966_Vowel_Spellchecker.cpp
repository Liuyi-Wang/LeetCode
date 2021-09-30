static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toLower(const string& S) {
        string s = S;
        for (int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
    
    string noVowel(const string& S) {
        string s = toLower(S);
        for (int i = 0; i < s.size(); ++i) {
            if ('a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i]) {
                s[i] = '*';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> caseInsensitive(wordlist.begin(), wordlist.end());
        unordered_map<string, int> caseSensitive;
        for (int i = wordlist.size()-1; i >= 0; --i) {
            caseSensitive[toLower(wordlist[i])] = i;
        }
        unordered_map<string, int> vowel;
        for (int i = wordlist.size()-1; i >= 0; --i) {
            vowel[noVowel(wordlist[i])] = i;
        }
        vector<string> result;
        for (const auto& q:queries) {
            if (caseInsensitive.find(q) != caseInsensitive.end()) {
                result.push_back(q);
            } else if (caseSensitive.find(toLower(q)) != caseSensitive.end()) {
                result.push_back(wordlist[caseSensitive[toLower(q)]]);
            } else if (vowel.find(noVowel(q)) != vowel.end()) {
                result.push_back(wordlist[vowel[noVowel(q)]]);
            } else {
                result.push_back("");
            }
        }
        return result;
    }
};
