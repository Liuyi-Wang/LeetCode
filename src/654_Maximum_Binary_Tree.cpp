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
    TreeNode* solve(const vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int index = begin;
        for (int i = begin+1; i <= end; ++i) {
            if (nums[index] < nums[i]) {
                index = i;
            }
        }
        TreeNode* node = new TreeNode(nums[index]);
        node->left = solve(nums, begin, index-1);
        node->right = solve(nums, index+1, end);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
