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
    // See detailed tutorials on:
    // https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem/2
    int rob(TreeNode* root) {
        vector<int> res = robSub(root);
        return max(res[0], res[1]);      
    }
private:
    vector<int> robSub(TreeNode* root) {
        if(!root) return vector<int>(2,0);

        vector<int> lres = robSub(root->left);
        vector<int> rres = robSub(root->right);

        vector<int> res(2,0);
        res[0] = max(lres[0], lres[1]) + max(rres[0], rres[1]);
        res[1] = root->val + lres[0] + rres[0];
        return res;
    }
};