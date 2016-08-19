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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        stack<TreeNode *> data;
        if(preorder.empty()) return root;
        root = new TreeNode(preorder[0]);
        data.push(root);
        int index = 0;
        for(int i=1;i<preorder.size();i++) {
            TreeNode *cur = data.top();
            if(data.top()->val != inorder[index]) {
                cur->left = new TreeNode(preorder[i]);
                data.push(cur->left);
            }
            else {
                while(!data.empty() && (data.top()->val ==  inorder[index])) {
                    cur = data.top();
                    data.pop();
                    index++;
                }
                if(index < inorder.size()) {
                    cur->right = new TreeNode(preorder[i]);
                    data.push(cur->right);
                }
            }
        }
        return root;
    }
};