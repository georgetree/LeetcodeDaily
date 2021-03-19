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
        if(!head||!head->next){
            return false;
        }
        ListNode *temp = head, *temp2 = head->next->next;
        while(temp!=NULL && temp2!=NULL){
            if(temp2==temp)
                return true;
            temp = temp->next;
            if(temp2->next==NULL)
                return false;
            temp2 = temp2->next->next;
        }
        return false;
    }
};