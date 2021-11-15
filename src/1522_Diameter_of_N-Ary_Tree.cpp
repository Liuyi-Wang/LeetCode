/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        d_result = 0;
        dfs(root);
        return d_result-1;
    }
    
    int dfs(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int l1 = 0, l2 = 0;
        for (auto child:root->children) {
            int l = dfs(child);
            if (l > l1) {
                l2 = l1;
                l1 = l;
            } else if (l > l2) {
                l2 = l;
            }
        }
        d_result = max(d_result, l1+l2+1);
        return max(l1, l2)+1;
    }
    
private:
    int d_result;
};
