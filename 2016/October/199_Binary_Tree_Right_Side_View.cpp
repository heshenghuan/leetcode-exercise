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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        getRightSideView(root, 1, result);
        return result;
    }
    // It is a DFS solution, a modified preorder traversal (DRL order) .
    // And use a variable 'level' to record the layer id of a TreeNode.
    // Each level should only have one most right side node added to result.
    void getRightSideView(TreeNode* root, int level, vector<int> &res) {
        if (!root) return;
        if (res.size() < level) 
            res.push_back(root->val);
        getRightSideView(root->right, level + 1, res);
        getRightSideView(root->left, level + 1, res);
    }
};