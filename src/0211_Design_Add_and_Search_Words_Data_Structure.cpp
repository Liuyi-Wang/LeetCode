/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class WordDictionary {
    struct Node {
        bool end;
        vector<Node*> children;
        Node(): end(false) {
            children = vector<Node*>(26, NULL);
        }
    };
    
    void insert(Node* node, const string& s, int i) {
        if (i == s.size()) {
            node->end = true;
            return;
        }
        if (!node->children[s[i]-'a']) {
            node->children[s[i]-'a'] = new Node();
        }
        insert(node->children[s[i]-'a'], s, i+1);
    }
    
    bool find(Node* node, const string& s, int i) {
        if (i == s.size()) {
            return node->end;
        }
        if (s[i] == '.') {
            for (int j = 0; j < node->children.size(); ++j) {
                if (node->children[j] && find(node->children[j], s, i+1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->children[s[i]-'a']) {
                return false;
            }
            return find(node->children[s[i]-'a'], s, i+1);
        }
    }
    
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        insert(root, word, 0);
    }
    
    bool search(string word) {
        return find(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
