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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode **p = &head;
        for(int i=0; i<left-1; i++){
            p = &(*p)->next;
        }
        ListNode  * const q = *p;
        for(int i=left; i<right; i++){
            ListNode * const temp = *p;
            *p = q->next;
            q->next = q->next->next;
            (*p)->next = temp;
        }
        return head;
        
    }
};