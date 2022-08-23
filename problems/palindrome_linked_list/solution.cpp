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
    bool isPalindrome(ListNode* head) {
        ListNode *t1 = head, *t2 = head;
        //取中間的node 
        while(t2 && t2->next){
            t1 = t1->next;
            t2 = t2->next->next;
        }
        ListNode *r = nullptr;
        while(t1){
            ListNode *temp = t1->next;
            t1->next = r;
            r = t1;
            t1 = temp;
        }
        while(r && head){
            if(r->val == head->val){
                r = r->next;
                head = head->next;
            }
            else return false;
        }
        return true;
    }
};