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
    bool balanced( TreeNode* root, int& depth ) {
        if( !root ) return true;
        int left = 0, right = 0;
        if( balanced( root->left, left) && balanced( root->right, right ) ) {
            if( abs(left - right) <= 1) {
                depth = 1 + max( left, right );
                return true;
            }
        }
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return balanced(root, depth);
    }
};