class Trie {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    Trie() {
        d_root = new Node();
    }
    
    void insertTrie(Node* node, const string& word, int i) {
        if (i == word.size()) {
            node->d_end = true;
            return;
        }
        if (NULL == node->d_children[word[i]-'a']) {
            node->d_children[word[i]-'a'] = new Node();
        }
        insertTrie(node->d_children[word[i]-'a'], word, i+1);
    }
    
    bool searchTrie(Node* node, const string& word, int i) {
        if (i == word.size()) {
            return node->d_end;
        }
        if (NULL == node->d_children[word[i]-'a']) {
            return false;
        }
        return searchTrie(node->d_children[word[i]-'a'], word, i+1);
    }
    
    bool searchWithTrie(Node* node, const string& word, int i) {
        if (i == word.size()) {
            return true;
        }
        if (NULL == node->d_children[word[i]-'a']) {
            return false;
        }
        return searchWithTrie(node->d_children[word[i]-'a'], word, i+1);
    }
    
    void insert(string word) {
        insertTrie(d_root, word, 0);
    }
    
    bool search(string word) {
        return searchTrie(d_root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return searchWithTrie(d_root, prefix, 0);
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
