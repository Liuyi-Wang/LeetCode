class Trie {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    /** Initialize your data structure here. */
    Trie() {
        d_root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = d_root;
        for (int i = 0; i < word.size(); ++i) {
            if (NULL == node->d_children[word[i]-'a']) {
                node->d_children[word[i]-'a'] = new Node();
            }
            node = node->d_children[word[i]-'a'];
        }
        node->d_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = d_root;
        for (int i = 0; i < word.size(); ++i) {
            if (NULL == node->d_children[word[i]-'a']) {
                return false;
            }
            node = node->d_children[word[i]-'a'];
        }
        return node->d_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = d_root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (NULL == node->d_children[prefix[i]-'a']) {
                return false;
            }
            node = node->d_children[prefix[i]-'a'];
        }
        return true;
    }
private:
    Node* d_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
