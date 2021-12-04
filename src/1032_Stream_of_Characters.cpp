class StreamChecker {
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    Node* root;
    string S;
public:
    void insert(Node* root, const string& word, int i) {
        if (i == -1) {
            root->d_end = true;
            return;
        }
        if (!root->d_children[word[i]-'a']) {
            root->d_children[word[i]-'a'] = new Node();
        }
        insert(root->d_children[word[i]-'a'], word, i-1);
    }
    
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (auto word:words) {
            insert(root, word, word.size()-1);
        }
    }
    
    bool query(char letter) {
        S += letter;
        Node* node = root;
        for (int i = S.size()-1; i >= 0; --i) {
            if (node->d_children[S[i]-'a']) {
                if (node->d_children[S[i]-'a']->d_end) {
                    return true;
                } else {
                    node = node->d_children[S[i]-'a'];
                }
            } else {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
