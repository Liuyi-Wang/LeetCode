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
    struct NodeInfo {
        int d_level;
        NodeInfo* d_parent;
        TreeNode* d_it;
        NodeInfo(int level, 
                 TreeNode* it): d_level(level),
                                d_it(it),
                                d_parent(NULL) {}
        NodeInfo(int level, 
                 TreeNode* it,
                 NodeInfo* parent): d_level(level),
                                    d_it(it),
                                    d_parent(parent) {}
    };
    
    TreeNode* recoverFromPreorder(string S) {
        S += "-";
        int index = 0;
        for (int i = 0; i < S.size(); ++i) {
            if ('-' == S[i]) {
                index = i;
                break;
            }
        }
        string val = S.substr(0, index);
        TreeNode* root = new TreeNode(atoi(val.c_str()));
        NodeInfo* root_info = new NodeInfo(0, root, NULL);
        
        int level = 0;
        NodeInfo* thisNode = root_info;
        while (index < S.size()) {
            if ('-' == S[index]) {
                ++level;
                ++index;
                continue;
            }
            int begin = index;
            while (index < S.size() && '-' != S[index]) {
                ++index;
            }
            val = S.substr(begin, index-begin);
            while (level <= thisNode->d_level) {
                thisNode = thisNode->d_parent;
            }
            TreeNode* parentNode = thisNode->d_it;
            TreeNode* treeNode = new TreeNode(atoi(val.c_str()));
            NodeInfo* nodeInfo = new NodeInfo(level, treeNode, thisNode);
            if (NULL == parentNode->left) {
                parentNode->left = treeNode;
            } else {
                parentNode->right = treeNode;
            }
            thisNode = nodeInfo;   
            level = 0;
        }
        return root;
    }
};
