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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while(pre->next){
            ListNode *cur = pre->next;
            while(cur->next && cur->val == cur->next->val){
                cur = cur->next;
            }
            if(cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return dummy->next;
    }
};