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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* res = nullptr;
        ListNode **p = &res;
        while(a && b){
            if(a->val > b->val){
                *p = b;
                b = b->next;
            }else{
                *p = a;
                a = a->next;
            }
            p = &((*p)->next);
        }
        *p = a == nullptr ? b : a;
        return res;

    }
};