class Solution {
public:
    struct Node {
        bool d_end;
        vector<Node*> d_children;
        vector<string> d_words;
        Node() {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    void insert(Node* root, const string& word, int i) {
        root->d_words.push_back(word);
        if (i == word.size()) {
            root->d_end = true;
            return;
        }
        if (root->d_children[word[i]-'a'] == NULL) {
            root->d_children[word[i]-'a'] = new Node();
        }
        insert(root->d_children[word[i]-'a'], word, i+1);
    }
    
    Node* find(Node* root, const string& word, int i) {
        if (i == word.size()) {
            return root;
        }
        if (root->d_children[word[i]-'a'] == NULL) {
            return NULL;
        }
        return find(root->d_children[word[i]-'a'], word, i+1);
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        d_root = new Node();
        for (auto word:words) {
            insert(d_root, word, 0);
        }
        for (auto word:words) {
            vector<string> square = {word};
            build(words, square, 1, word.size());
        }
        return d_result;
    }
    
    void build(const vector<string>& words, vector<string>& square, int i, int n) {
        if (i == n) {
            d_result.push_back(square);
            return;
        }
        string s;
        for (int j = 0; j < i; ++j) {
            s += square[j][i];
        }
        Node* node = find(d_root, s, 0);
        if (node == NULL) {
            return;
        }
        for (int j = 0; j < node->d_words.size(); ++j) {
            square.push_back(node->d_words[j]);
            build(words, square, i+1, n);
            square.pop_back();
        }
    }
    
private:
    Node* d_root;
    vector<vector<string>> d_result;
};
