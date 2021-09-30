class StreamChecker {
public:
    struct Node {
        vector<Node*> d_c;
        bool d_end;
        Node(): d_end(false) {
            d_c = vector<Node*>(26, NULL);
        }
    };
    
    StreamChecker(vector<string>& words): d_root(NULL), max_l(0), d_last("") {
        d_root = new Node();
        for (auto word:words) {
            insertWord(d_root, word, word.size()-1);
            max_l = max(max_l, int(word.size()));
        }
    }
    
    bool query(char letter) {
        d_last += letter;
        int len = min(max_l, int(d_last.size()));
        string temp = d_last.substr(d_last.size()-len);
        if (inList(temp, temp.size()-1, d_root)) {
            return true;
        }
        return false;
    }

private:
    Node* d_root;
    int max_l;
    string d_last;
    
    void insertWord(Node* root, const string& word, int index) {
        if (0 > index) {
            root->d_end = true;
            return;
        }
        if (NULL == root->d_c[word[index]-'a']) {
            root->d_c[word[index]-'a'] = new Node();
        }
        insertWord(root->d_c[word[index]-'a'], word, index-1);
    }
    
    bool inList(const string& temp, int index, Node* root) {
        if (root->d_end) {
            return true;
        }
        if (index < 0) {
            return false;
        }
        if (NULL == root->d_c[temp[index]-'a']) {
            return false;
        }
        return inList(temp, index-1, root->d_c[temp[index]-'a']);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
