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
    ListNode* partition(ListNode* head, int x) {
        ListNode *t1 = new ListNode(0), *t2 = new ListNode(0);
        ListNode *dummy1 = t1 , *dummy2 = t2;
        while(head){
            if(head->val<x){
                t1->next = head;
                t1 = t1->next;
            }else{
                t2->next = head;
                t2 = t2->next;
            }
            head = head->next;
        }
        t2->next = nullptr;
        t1->next = dummy2->next;
        return dummy1->next;
    }
};