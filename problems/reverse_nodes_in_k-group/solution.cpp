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
        ListNode *temp = head;
        for(int i=1; i<k && temp!=NULL; i++){
                temp = temp->next;
            }
        if(temp==NULL)
            return head;
        ListNode *tempNode = temp->next;
        temp->next = NULL;
        
        ListNode *newlist = reverseList(head);
        ListNode *newhead = reverseKGroup(tempNode,k);
        head->next = newhead;
        return newlist;
    }
 
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = nullptr;
        while(head){
            ListNode *ne = head->next;
            head->next = cur;
            cur = head;
            head = ne;
        }
        return cur;
    }


};