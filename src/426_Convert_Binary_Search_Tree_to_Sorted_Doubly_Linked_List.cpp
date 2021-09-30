/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (NULL == root) {
            return NULL;
        }
        Node* l = treeToDoublyList(root->left);
        Node* r = treeToDoublyList(root->right);
        
        if (NULL != l && NULL != r) {
            Node* ltail = l->left;
            ltail->right = root;
            root->left = ltail;
            
            Node* rtail = r->left;
            root->right = r;
            r->left = root;
            
            l->left = rtail;
            rtail->right = l;
            return l;
        }
        if (NULL != l) {
            Node* ltail = l->left;
            ltail->right = root;
            root->left = ltail;
            root->right = l;
            l->left = root;
            return l;
        }
        if (NULL != r) {
            Node* rtail = r->left;
            root->right = r;
            r->left = root;
            root->left = rtail;
            rtail->right = root;
            return root;
        }
        root->left = root;
        root->right = root;
        return root;
    }
};
