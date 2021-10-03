class SegmentTree {
public:
    struct Node {
        int d_l;
        int d_r;
        Node* d_lnode;
        Node* d_rnode;
        long long d_count;
        Node(int l, int r): d_l(l), d_r(r), d_lnode(NULL), d_rnode(NULL), d_count(0) {}
    };
    
    SegmentTree(int l, int r) {
        d_root = new Node(l, r);
        initTree(d_root);
    }
    
    void updateSingle(int i) {
        update(d_root, i);
    }
    
    long long queryRange(int l, int r) {
        if (l > r) {
            return 0;
        }
        return query(d_root, l, r);
    }
private:
    Node* d_root;
    
    void initTree(Node* root) {
        if (root->d_l == root->d_r) {
            return;
        }
        int mid = root->d_l+(root->d_r-root->d_l)/2;
        root->d_lnode = new Node(root->d_l, mid);
        initTree(root->d_lnode);
        root->d_rnode = new Node(mid+1, root->d_r);
        initTree(root->d_rnode);
    }
    
    void update(Node* root, int i) {
        if (i < root->d_l || i > root->d_r) {
            return;
        }
        if (i == root->d_l && i == root->d_r) {
            ++root->d_count;
            return;
        }
        update(root->d_lnode, i);
        update(root->d_rnode, i);
        root->d_count = root->d_lnode->d_count + root->d_rnode->d_count;
    }
    
    long long query(Node* root, int l, int r) {
        if (root->d_r < l || r < root->d_l) {
            return 0;
        }
        if (l <= root->d_l && root->d_r <= r) {
            return root->d_count;
        }
        return query(root->d_lnode, l, r) + query(root->d_rnode, l, r);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int M = 1e9+7;
        vector<int> v = instructions;
        sort(v.begin(), v.end());
        unordered_map<int, int> instructionToIndex;
        instructionToIndex[v[0]] = 0;
        int index = 1;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] == v[i-1]) {
                continue;
            }
            instructionToIndex[v[i]] = index++;
        }
        SegmentTree tree(0, instructionToIndex.size()-1);
        long long result = 0;
        for (auto instruction:instructions) {
            int index = instructionToIndex[instruction];
            long long l = tree.queryRange(0, index-1);
            long long r = tree.queryRange(index+1, instructionToIndex.size()-1);
            //cout << "insrt" << instruction << ",index=" << index << ",l=" << l << ",r=" << r << endl;
            result += min(l, r);
            tree.updateSingle(index);
        }
        return result%M;
    }
};
