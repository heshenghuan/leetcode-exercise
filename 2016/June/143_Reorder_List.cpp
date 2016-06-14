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
    // Split list to 2 half, and merge them.
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        // find mid node
        ListNode* mid = findMidNode(head);
        // reverse the lists after mid node
        mid = reverseList(mid);
        ListNode* tmp = head;
        // reorder the list
        while(tmp) {
            if(!tmp->next) {
                tmp->next = mid;
                break;
            }
            else {
                ListNode *tmp1 = tmp->next, *tmp2 = mid->next;
                tmp->next = mid;
                mid->next = tmp1;
                mid = tmp2;
                tmp = tmp1;
            }
        }
        return;
    }

    // Find the node in the middle of list
    ListNode* findMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL; // IMPORTANT! splited the list
        return fast;
    }

    // Reverse the list given by head
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = head;
        ListNode* curr;
        while(prev->next) {
            curr = prev->next;
            prev->next = prev->next->next;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};