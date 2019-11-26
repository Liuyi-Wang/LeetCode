static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

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
    TreeNode* solve(const vector<int> &nums, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int mid = l+(r-l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, l, mid-1);
        root->right = solve(nums, mid+1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
