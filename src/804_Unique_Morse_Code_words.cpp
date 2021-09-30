class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> result;
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (const auto& w:words) {
            string s;
            for (auto& c:w) {
                s += table[c-'a'];
            }
            result.insert(s);
        }
        return result.size();
    }
};
