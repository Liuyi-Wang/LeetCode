static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct Node {
        bool end;
        vector<Node*> children;
        Node(): end(false) {
            children = vector<Node*>(26, NULL);
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for (const auto &word:words) {
            insert(word, root, 0);
        }
        vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
        di = {-1, 0, 1, 0};
        dj = {0, 1, 0, -1};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                find(board, v, i, j, "", root);
            }
        }
        return result;
    }

private:
    Node *root;
    vector<string> result;
    vector<int> di;
    vector<int> dj;
    
    void insert(const string &word, Node* node, int i) {
        if (i == word.size()) {
            node->end = true;
            return;
        }
        if (NULL == node->children[word[i]-'a']) {
            node->children[word[i]-'a'] = new Node();
        }
        insert(word, node->children[word[i]-'a'], i+1);
    }
    
    void find(const vector<vector<char>> &board, vector<vector<bool>> &v, int i, int j, string s, Node *node) {
        if (NULL == node->children[board[i][j]-'a']) {
            return;
        }
        if (node->children[board[i][j]-'a']->end) {
            result.push_back(s+board[i][j]);
            node->children[board[i][j]-'a']->end = false;
        }
        v[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int I = i+di[k];
            int J = j+dj[k];
            if (I < 0 || J < 0 || I >= board.size() || J >= board[0].size() || v[I][J]) {
                continue;
            }
            find(board, v, I, J, s+board[i][j], node->children[board[i][j]-'a']);
        }
        v[i][j] = false;
    }
};
