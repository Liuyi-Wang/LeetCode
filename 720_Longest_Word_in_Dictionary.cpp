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
        vector<Node*> d_children;   
        Node(): d_end(false) {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    void insert(Node *root, const string &s) {
        for (int i = 0; i < s.size(); ++i) {
            if (NULL == root->d_children[s[i]-'a']) {
                root->d_children[s[i]-'a'] = new Node();
            }
            root = root->d_children[s[i]-'a'];
        }
        root->d_end = true;
    }
    
    bool check(Node *root, const string &s) {
        for (int i = 0; i < s.size(); ++i) {
            if (NULL == root->d_children[s[i]-'a']) {
                return false;
            }
            root = root->d_children[s[i]-'a'];
            if (!root->d_end) {
                return false;
            }
        }
        return true;
    }
    
    string longestWord(vector<string>& words) {
        Node *root = new Node();
        for (const auto &w:words) {
            insert(root, w);
        }
        string result;
        for (const auto &w:words) {
            if (check(root, w)) {
                if (result.size() < w.size()) {
                    result = w;
                } else if (result.size() == w.size() && result > w) {
                    result = w;
                }
            }
        }
        return result;
    }
};
