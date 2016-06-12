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
    * 两个指针small和big分别指向l1和l2头部较小和较大的数
    * 然后不断比较small->next是否大于big，如果是将big接在small->next后，交换small和big
    * 如果不是，则small往后移，再比较，不断重复这个过程，最后将还未比较的big拼接在small->next后即可
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *small, *big, *head;
        small = l1->val > l2->val?l2:l1;
        big = l1->val > l2->val?l1:l2;
        head = small;
        while(small->next!=NULL) {
            if (small->next->val >= big->val){
                ListNode* tmp = small->next;
                small->next = big;
                small = big;
                big = tmp;
            }
            else {
                small = small->next;
            }
        }
        small->next = big;
        return head;
    }
};