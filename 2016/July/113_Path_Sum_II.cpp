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
    vector<vector<int> > result;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        if(!root) return result;
        findPaths(root, sum, path);
        return result;
    }
    void findPaths(TreeNode* root, int sum, vector<int> &path) {
        if(root->val == sum && !root->left && !root->right)
        {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left){
            path.push_back(root->val);
            findPaths(root->left, sum - root->val, path);
            path.pop_back();
        }
        if(root->right) {
            path.push_back(root->val);
            findPaths(root->right, sum - root->val, path);
            path.pop_back();
        }
        return;
    }
};