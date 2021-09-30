class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {   
        stringstream ss(text);
        string temp;
        vector<string> words;
        while (getline(ss, temp, ' ')) {
            words.push_back(temp);
        }
        vector<string> result;
        if (words.size() < 3) {
            return result;
        }
        for (int i = 0; i < words.size()-2; ++i) {
            if (first == words[i] && second == words[i+1]){
                result.push_back(words[i+2]);
            }
        }
        return result;
    }
};
