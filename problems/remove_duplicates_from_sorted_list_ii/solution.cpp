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
        ListNode **p = &head;
        while(*p){
            if((*p)->next && (*p)->val == (*p)->next->val  ){
                ListNode *temp = *p;
                while(temp && temp->val == (*p)->val)
                    temp = temp->next;
                *p = temp;   
            }else{
                p = &((*p)->next);    
            }
        }
        return head;
    }
};