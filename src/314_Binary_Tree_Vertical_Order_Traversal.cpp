static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (NULL == root) {
            return result;
        }
        map<int, vector<int>> d_hash;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            int index = q.front().first;
            root = q.front().second;
            q.pop();
            d_hash[index].push_back(root->val);
            if (root->left) {
                q.push({index-1, root->left});
            }
            if (root->right) {
                q.push({index+1, root->right});
            }
        }
        for (map<int, vector<int>>::iterator it = d_hash.begin(); it != d_hash.end(); ++it) {
            result.push_back(it->second);
        } 
        return result;
    }
};
