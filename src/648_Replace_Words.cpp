static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_v;
        Node(): d_end(false), d_v(vector<Node*>(26, NULL)) {}
    };

    int search(const string &s, int i, Node *node) {
        if (NULL == node) {
            return -1;
        }
        if (node->d_end) {
            return i;
        }
        if (i == s.size()) {
            return -1;
        }
        if (NULL == node->d_v[s[i]-'a']) {
            return -1;    
        }
        return search(s, i+1, node->d_v[s[i]-'a']);
    }
                                  
    void build(const string &s, int i, Node *node) {
        if (i == s.size()) {
            node->d_end = true;
            return;
        }
        if (NULL == node->d_v[s[i]-'a']) {
            node->d_v[s[i]-'a'] = new Node();
        }
        build(s, i+1, node->d_v[s[i]-'a']);
    }
                                  
    string replaceWords(vector<string>& dict, string sentence) {
        Node *root = new Node();
        for (const auto &d:dict) {
            build(d, 0, root);
        }
        int l = 0, r = 0;
        string result;
        while (r < sentence.size()) {
            if (' ' == sentence[r]) {
                string word = sentence.substr(l, r-l);
                int len = search(word, 0, root);
                if (-1 == len) {
                    result += word+" ";
                } else {
                    result += word.substr(0, len)+" ";
                }
                l = r+1;
                r = l;
            } else {
                ++r;
            }
        }
        string word = sentence.substr(l, r-l);
        int len = search(word, 0, root);
        if (-1 == len) {
            result += word;
        } else {
            result += word.substr(0, len);
        }
        return result;
    }
};
