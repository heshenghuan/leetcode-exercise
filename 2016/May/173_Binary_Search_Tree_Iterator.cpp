/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    /*
    * 题目中的BST是一个排好序的升序树，因此依次访问树中next smallest number其实就是一个LDR遍历
    * Note中要求next()和hasNext()的时间复杂度都是O(1)，且空间复杂度为O(h)，h为树高
    * 那这显然应该是一个变形的非递归LDR遍历了，构造器的部分相当于遍历根节点的所有左子树
    * next()部分则是之后的遍历，按照非递归LDR遍历的思想去写即可。
    */
    BSTIterator(TreeNode *root) {
        // L-subtree traversal
        while(root != NULL) {
            stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!stack.empty());
    }

    /** @return the next smallest number */
    int next() {
        // D manipulate the data
        TreeNode* curr = stack.top();
        int re_val = curr->val;
        stack.pop();
        // R-subtree traversal
        curr = curr->right;
        while(curr != NULL) {
            stack.push(curr);
            curr = curr->left;
        }
        return re_val;
    }
private:
    std::stack<TreeNode* > stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */