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
    vector<vector<int> > ans;
    void solution(TreeNode* root, int depth) {
        if(root == NULL) return;
        if(ans.size() == depth) {
            ans.push_back(vector<int> ());
        }
        ans[depth].push_back(root->val);
        solution(root->left, depth+1);
        solution(root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solution(root, 0);
        return ans;
    }
};