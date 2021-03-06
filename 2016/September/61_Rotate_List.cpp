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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        
        /* find the tail of list */
        while(tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        /* form a cycle*/
        tail->next = head;
        k = k % len;
        
        /* Rotate the list to the right by k place, i.e. to left by (len - k) place*/
        for (int i = 0; i < len - k; i++)
            tail = tail->next;
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
