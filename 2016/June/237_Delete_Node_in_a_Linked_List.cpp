/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // if *node is the tail node or the List is empty
        if(node->next == NULL) return;
        // delete the node
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};