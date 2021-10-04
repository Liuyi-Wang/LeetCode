struct Node {
    int d_l;
    int d_r;
    int d_val;
    int d_pos;
    Node* d_lnode;
    Node* d_rnode;
    Node(int l, int r): d_l(l), d_r(r), d_val(0), d_pos(0), d_lnode(NULL), d_rnode(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& target) {
        d_root = new Node(0, target.size()-1);
        init(d_root, target);
    }
    
    pair<int, int> queryRange(int l, int r) {
        return query(d_root, l, r);
    }
private:
    Node* d_root;
    
    void init(Node* root, const vector<int>& target) {
        if (root->d_l == root->d_r) {
            root->d_val = target[root->d_l];
            root->d_pos = root->d_l;
            return;
        }
        int mid = root->d_l+(root->d_r-root->d_l)/2;
        root->d_lnode = new Node(root->d_l, mid);
        init(root->d_lnode, target);
        root->d_rnode = new Node(mid+1, root->d_r);
        init(root->d_rnode, target);
        if (root->d_lnode->d_val < root->d_rnode->d_val) {
            root->d_val = root->d_lnode->d_val;
            root->d_pos = root->d_lnode->d_pos;
        } else {
            root->d_val = root->d_rnode->d_val;
            root->d_pos = root->d_rnode->d_pos;
        }
    }
    
    pair<int, int> query(Node* root, const int& l, const int& r) {
        if (root->d_l > r || root->d_r < l) {
            return {0, INT_MAX};    
        }
        if (l <= root->d_l && root->d_r <= r) {
            return {root->d_pos, root->d_val};
        }
        pair<int, int> pl = query(root->d_lnode, l, r);
        pair<int, int> pr = query(root->d_rnode, l, r);
        if (pl.second < pr.second) {
            return pl;
        }
        return pr;
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = 0;
        SegmentTree tree(target);
        dfs(0, target.size()-1, result, 0, target, tree);
        return result;
    }
    
    void dfs(int l, int r, int& result, int base, const vector<int>& target, SegmentTree& tree) {
        if (l > r) {
            return;
        }
        if (l == r) {
            result += target[l]-base;
            return;
        }
        pair<int, int> p = tree.queryRange(l, r);
        result += p.second-base;
        dfs(l, p.first-1, result, p.second, target, tree);
        dfs(p.first+1, r, result, p.second, target, tree);
    }
};
