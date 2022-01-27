/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
    struct Node {
        Node* d_0;
        Node* d_1;
        Node(): d_0(NULL), d_1(NULL) {}
    };
    
    void insert(Node* node, const int& num, int i) {
        if (i == -1) {
            return;
        }
        int d = ((num>>i)&1);
        if (d == 0) {
            if (!node->d_0) {
                node->d_0 = new Node();
            }
            insert(node->d_0, num, i-1);
        } else {
            if (!node->d_1) {
                node->d_1 = new Node();
            }
            insert(node->d_1, num, i-1);
        }
    }
    
    int find(Node* node, const int& num, int i, int result) {
        if (i == -1) {
            return result;
        }
        int d = ((num>>i)&1);
        if (d == 0) {
            if (node->d_1) {
                return find(node->d_1, num, i-1, result+(1<<i));
            }
            return find(node->d_0, num, i-1, result);
        } else {
            if (node->d_0) {
                return find(node->d_0, num, i-1, result+(1<<i));
            }
            return find(node->d_1, num, i-1, result);
        }
    }
    Node* d_root;
public:
    int findMaximumXOR(vector<int>& nums) {
        d_root = new Node();
        for (auto num:nums) {
            insert(d_root, num, 31);
        }
        int result = INT_MIN;
        for (auto num:nums) {
            result = max(result, find(d_root, num, 31, 0));
        }
        return result;
    }
};
