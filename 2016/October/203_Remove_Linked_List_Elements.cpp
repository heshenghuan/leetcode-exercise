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
    ListNode* removeElements(ListNode* head, int val) {
        // Runtime: 26ms
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* pre = p;
        ListNode* cur = p->next;
        while(cur) {
            if(cur->val == val){
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return p->next;
    }
};