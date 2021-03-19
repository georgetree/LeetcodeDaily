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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){
            return nullptr;
        }
        ListNode *temp = head, *temp2 = head, *temp3 = head;
        while(temp2 && temp2->next){
            temp = temp -> next;
            temp2 = temp2->next->next;
            if(temp2==temp){
                while(temp2!=temp3){
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
                return temp3;   
            }
        }
        return nullptr;
    }
};