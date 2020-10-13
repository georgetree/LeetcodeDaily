/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3(0);
        ListNode *l3_tail = &l3;
        int carry = 0;
        while(l1||l2||carry){
            carry += (l1 ? l1->val : 0 ) + (l2 ? l2->val : 0);
            l3_tail->next = new ListNode(carry % 10);
            carry /= 10;
            l1 = l1 ? l1->next :nullptr;
            l2 = l2 ? l2->next :nullptr;
            l3_tail = l3_tail->next;
        }
        return l3.next;
    }
};