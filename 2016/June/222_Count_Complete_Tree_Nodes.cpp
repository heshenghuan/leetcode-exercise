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
    /*
     * 利用完全二叉树的性质，仅有最后一层结点不满，且是从右向左连续缺若干结点（比满二叉树少最后几个）
     * 满二叉树高度为h，则其结点数为 2^h-1 个
     * 一个完全二叉树如果不是满二叉树，则不断按左右子树递归处理，其子树最终会是蛮二叉树
     * 例如：
     *                    1
     *                  /   \
     *                 2     3
     *               /   \
     *              4     5
     * 该二叉树是一个完全二叉树，其根节点的左子树是满二叉树而右子树不是
     * 分别得到根节点往左往右到叶子结点的深度，如果两个数相同则该树为满二叉树，否则按照递归处理。
     */
    int getLeftDepth(TreeNode* root) {
        int depth = 0;
        while(root){
            ++depth;
            root = root->left;
        }
        return depth;
    }
    int getRightDepth(TreeNode* root) {
        int depth = 0;
        while(root){
            ++depth;
            root = root->right;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int l = getLeftDepth(root);
        int r = getRightDepth(root);
        
        if(l == r) return (2<<(l-1)) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};