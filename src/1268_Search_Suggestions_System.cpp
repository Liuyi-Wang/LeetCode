class Solution {
public:
    struct Node {
        vector<Node*> d_children;
        vector<string> d_suggestions;
        Node() {
            d_children = vector<Node*>(26, NULL);
        }
    };
    
    void insert(Node* root, const string &product, int i) {
        if (i == product.size()) {
            return;
        }
        if (root->d_children[product[i]-'a'] == NULL) {
            Node* node = new Node();
            root->d_children[product[i]-'a'] = node;
        }
        root = root->d_children[product[i]-'a'];
        if (root->d_suggestions.size() < 3) {
            root->d_suggestions.push_back(product);
        } else if (root->d_suggestions[2] > product) {
            root->d_suggestions[2] = product;
        }
        sort(root->d_suggestions.begin(), root->d_suggestions.end());
        insert(root, product, i+1);
    }

    void suggest(Node* root, const string &product, int i, vector<vector<string>>& result) {
        if (i == product.size()) {
            return;
        }
        if (root->d_children[product[i]-'a'] == NULL) {
            return;
        }
        root = root->d_children[product[i]-'a'];
        result.push_back(root->d_suggestions);
        suggest(root, product, i+1, result);
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<string>& A = products;
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
