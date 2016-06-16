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
    // 20ms
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head, *post = head->next;
        while(prev&&post) {
            if (post->val == prev->val) {
                ListNode* tmp = post->next;
                prev->next = tmp;
                post = tmp;
            }
            else {
                prev = prev->next;
                post = prev->next;
            }
        }
        return head;
    }
    // 16ms
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head;
        while(prev->next) {
            if (prev->val == prev->next->val) {
                prev->next = prev->next->next;
            }
            else {
                prev = prev->next;
            }
        }
        return head;
    }
};