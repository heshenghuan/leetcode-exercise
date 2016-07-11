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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        // if(root->val < sum) return false; /* the sum could be a negative int, this sentence is wrong & needless*/
        
        /* 
         * make sure the path is a root-to-leaf path
         * so if root->val == sum, root should be a leaf node
         */ 
        if(root->val == sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};