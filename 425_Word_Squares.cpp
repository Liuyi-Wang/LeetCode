static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct Node {
        vector<int> d_i;
        vector<Node*> d_node;
        Node(): d_node(26, NULL) {}
    };
    
    void build(const vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            Node* node = root;
            for (auto c:words[i]) {
                if (NULL == node->d_node[c-'a']) {
                    node->d_node[c-'a'] = new Node();
                }
                node = node->d_node[c-'a'];
                node->d_i.push_back(i);
            }
        }
    }
    
    void solve(int col, const vector<string>& words, 
               vector<vector<string>>& results, vector<string>& result) {
        if (col == words[0].size()) {
            results.push_back(result);
            return;
        }
        string pre;
        for (int i = 0; i < col; ++i) {
            pre += result[i][col];
        }
        Node* node = root;
        for (int i = 0; i < pre.size(); ++i) {
            if (NULL == node->d_node[pre[i]-'a']) {
                return;
            }
            node = node->d_node[pre[i]-'a'];
        }
        for (auto index:node->d_i) {
            result.push_back(words[index]);
            solve(col+1, words, results, result);
            result.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        root = new Node();
        build(words);
        vector<vector<string>> results;
        for (const auto& word:words) {
            vector<string> result = {word};
            solve(1, words, results, result);
        }
        return results;
    }
    
private:
    Node* root;
};
