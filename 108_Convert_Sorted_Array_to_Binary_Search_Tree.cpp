/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        return recursion(nums, 0, nums.size()-1);
    }
    
    TreeNode* recursion(const vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int mid = begin+(end-begin)/2;
        TreeNode* l = recursion(nums, begin, mid-1);
        TreeNode* r = recursion(nums, mid+1, end);
        return new TreeNode(nums[mid], l, r);
    }
};
