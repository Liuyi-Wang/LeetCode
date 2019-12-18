static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MagicDictionary {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        d_root = new Node();
    }
    
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
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const auto &word:dict) {
            insert(word);
        }
    }
    
    bool solve(const string &word, int i, Node* node, bool m) {
        if (i == word.size()) {
            return node->d_end && m;
        }
        if (NULL == node->d_children[word[i]-'a'] && m) {
            return false;
        } else if (NULL == node->d_children[word[i]-'a']) {
            for (int j = 0; j < node->d_children.size(); ++j) {
                if (NULL == node->d_children[j]) {
                    continue;
                }
                if (solve(word, i+1, node->d_children[j], true)) {
                    return true;
                }
            }
            return false;
        }
        if (solve(word, i+1, node->d_children[word[i]-'a'], m)) {
            return true;
        }
        if (m) {
            return false;
        }
        for (int j = 0; j < node->d_children.size(); ++j) {
            if (NULL == node->d_children[j] || j == word[i]-'a') {
                continue;
            }
            if (solve(word, i+1, node->d_children[j], true)) {
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return solve(word, 0, d_root, false);
    }
    
private:
    Node* d_root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
