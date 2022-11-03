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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *f = head->next, *s = head;
        while(f && f->next){
            if(f==s) return true;
            s = s->next;
            f = f->next->next;
        }
        return false;
    }
};