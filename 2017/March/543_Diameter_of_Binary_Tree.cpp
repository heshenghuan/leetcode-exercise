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
    int depthOfBinaryTree(TreeNode* root, int &max_res) {
        if(!root) return 0;
        int leDepth = depthOfBinaryTree(root->left, max_res);
        int riDepth = depthOfBinaryTree(root->right, max_res);
        if (leDepth + riDepth > max_res) max_res = leDepth + riDepth;
        return 1 + max(leDepth, riDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_res = 0;
        depthOfBinaryTree(root, max_res);
        return max_res;
    }
};