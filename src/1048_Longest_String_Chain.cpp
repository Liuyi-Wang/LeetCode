class Solution {
public:
    struct longer {
        inline bool operator() (const string& s1, const string& s2) {
            return s1.size() > s2.size();
        }    
    };
    
    int longest(const string& s, unordered_map<string, int>& lens) {
        int result = lens[s];
        if (0 != result) {
            return result;
        }
        result = 1;
        for (int i = 0; i < s.size(); ++i) {
            string next = s;
            next.erase(next.begin()+i);
            if (lens.find(next) == lens.end()) {
                continue;
            }
            if (0 == lens[next]) {
                lens[next] = longest(next, lens);
            }
            result = max(result, 1+lens[next]);
            //if (result == s.size()) {
                lens[s] = result;
                return result;
            //}
        }
        lens[s] = result;
        return result;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), longer());
        unordered_map<string, int> lens;
        for (auto s:words) {
            lens[s] = 0;
        }
        int result = 1;
        for (auto s:words) {
            if (result >= s.size()) {
                return result;
            }
            result = max(result, longest(s, lens));
        }
        return result;
    }
};
