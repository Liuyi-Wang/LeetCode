/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> hash;
        unordered_set<char> s1, s2;
        for (int i = 0; i < str1.size(); ++i) {
            s1.insert(str1[i]);
            s2.insert(str2[i]);
            if (hash.find(str1[i]) == hash.end()) {
                hash[str1[i]] = str2[i];
                continue;
            }
            if (hash[str1[i]] != str2[i]) {
                return false;
            }
        }
        if (s1.size() == 26 && s2.size() == 26) {
            return str1 == str2;
        }
        return true;
    }
};
