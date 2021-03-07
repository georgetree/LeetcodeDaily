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
        ListNode **p;
        p = &head;
        while(*p){
            if( (*p)->next && (*p)->val == (*p)->next->val){
                ListNode *tmp = *p;
                while(tmp->next && tmp->val == tmp->next->val){
                    tmp = tmp->next;
                }
                *p = tmp;
            }else{
                p = &(*p)->next;
            }
        }
        return head;
    }
};