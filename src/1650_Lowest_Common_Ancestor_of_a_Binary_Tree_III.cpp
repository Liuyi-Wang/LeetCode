/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        p_hash.insert(p->val);
        while (p->parent) {
            p = p->parent;
            p_hash.insert(p->val);
        }
        if (p_hash.find(q->val) != p_hash.end()) {
            return q;
        }
        while (true) {
            q = q->parent;
            if (p_hash.find(q->val) != p_hash.end()) {
                return q;
            }
        }
        return NULL;
    }
    
    
private:
    unordered_set<int> p_hash;
};
