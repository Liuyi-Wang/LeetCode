auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class WordDictionary {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        d_root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = d_root;
        for (int i = 0; i < word.size(); ++i) {
            if (NULL == node->d_children[word[i]-'a']) {
                node->d_children[word[i]-'a'] = new Node();
            }
            node = node->d_children[word[i]-'a'];
        }
        node->d_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, 0, d_root);
    }
private:
    Node* d_root;
    
    bool searchWord(const string& word, int begin, Node* node) {
        for (int i = begin; i < word.size(); ++i) {
            if ('.' == word[i]) {
                for (int j = 0; j < 26; ++j) {
                    if (NULL != node->d_children[j]) {
                        bool isValid = searchWord(word, i+1, node->d_children[j]);
                        if (isValid) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                if (NULL == node->d_children[word[i]-'a']) {
                    return false;
                }
                node = node->d_children[word[i]-'a'];
            }
        }
        return node->d_end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
