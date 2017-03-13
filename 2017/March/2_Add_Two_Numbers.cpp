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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        int k = 0, val = 0;
        while(l1 && l2){
            val = l1->val + l2->val + k;
            k = (val >= 10) ? 1:0;
            p->val = val % 10;
            if (l1->next && l2->next){
                p->next = new ListNode(0);
                p = p->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            val = l1->val + k;
            k = (val >= 10) ? 1:0;
            p->next = new ListNode(val % 10);
            p = p->next;
            l1 = l1->next;
        }
        while(l2){
            val = l2->val + k;
            k = (val >= 10) ? 1:0;
            p->next = new ListNode(val % 10);
            p = p->next;
            l2 = l2->next;
        }
        if (k) {
            p->next = new ListNode(1);
        }
        return ans;
    }
};