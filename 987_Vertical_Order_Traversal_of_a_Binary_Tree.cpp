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
    struct less_than {
        inline bool operator() (const pair<int, int>& p1,
                                const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        }    
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        d_x_y[root] = pair<int, int>(0, 0);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int x = d_x_y[node].first;
            int y = d_x_y[node].second;
            d_hash[x].push_back(pair<int, int>(y, node->val));
            if (NULL != node->left) {
                q.push(node->left);
                d_x_y[node->left] = pair<int, int>(x-1, y+1); 
            }
            if (NULL != node->right) {
                q.push(node->right);
                d_x_y[node->right] = pair<int, int>(x+1, y+1); 
            }
        }
        vector<vector<int>> result;
        for (map<int, vector<pair<int, int>>>::iterator it = d_hash.begin(); it != d_hash.end(); ++it) {
            sort(it->second.begin(), it->second.end(), less_than());
            vector<int> nodes;
            for (int i = 0; i < it->second.size(); ++i) {
                nodes.push_back(it->second[i].second);
            }
            result.push_back(nodes);
        }
        return result;
    }
private:
    map<int, vector<pair<int, int>> > d_hash;
    unordered_map<TreeNode*, pair<int, int> > d_x_y;
};
