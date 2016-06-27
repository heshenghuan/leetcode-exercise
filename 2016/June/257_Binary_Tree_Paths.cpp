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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findPaths(root, "", ans);
        return ans;
    }
    
    void findPaths(TreeNode* root, string path, vector<string> &result) {
        if(!root) return;
        if(!root->left && !root->right)
        {
            result.push_back(path + to_string(root->val));
            return;
        }
        
        string next_path = path + to_string(root->val) + "->";
        findPaths(root->left, next_path, result);
        findPaths(root->right, next_path, result);
    }
};