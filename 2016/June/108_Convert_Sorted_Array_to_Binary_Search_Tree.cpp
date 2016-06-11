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
    TreeNode* _sortedArrayToBST(vector<int>& num, int start, int end){  
        if(start==end)  
            return new TreeNode(num[start]);  
        if(start>end) {  
            return NULL;  
        }  
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(num[mid]);  
        root->left=_sortedArrayToBST(num, start,mid-1);  
        root->right=_sortedArrayToBST(num,mid+1,end);  
        return root; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};