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
    /*
    * 思路非常简单，按照x把原有链表分成两个，然后把两个链表拼接即可
    */
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(0);
        ListNode* q = new ListNode(0);
        ListNode* pHead = p;
        ListNode* qHead = q;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                p->next = head;
                p = p->next;
            }
            else
            {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        p->next = qHead->next;
        q->next = NULL;
        return pHead->next;
    }
};