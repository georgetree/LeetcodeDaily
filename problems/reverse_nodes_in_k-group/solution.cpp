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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
        dummy->next = head;
        int count = 1;
        while (cur!=nullptr) {
            if (count % k == 0) {
                pre = helper(pre,cur->next);
                cout << pre->val;
                cur = pre->next;
            }
            else cur = cur->next;
            ++count;
        }
        return dummy->next;
    }
    ListNode* helper(ListNode *h, ListNode *tail){
        ListNode *p = h->next;
        ListNode *cur = p->next;
        while (cur != tail) {
            p->next = cur->next;
            cur->next = h->next;
            h->next = cur;
            cur = p->next;
        }
        return p;
    }
};