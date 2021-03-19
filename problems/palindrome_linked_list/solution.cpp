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
    ListNode *reverse (ListNode* newHead) {
        ListNode *prev=NULL, *nextNode, *curr=newHead;
        
        while (curr!=NULL) {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return true;
        ListNode *slow=head,*fast=head->next;
        
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //ListNode *temp=slow->next;
        
        ListNode* newHead=reverse(slow->next);
        slow->next=NULL;
        
        while (newHead!=NULL && head!=NULL) {
        // cout<<"newHead "<<newHead->val<<endl;
        // cout<<"original head "<<head->val<<endl;
            if (newHead->val!=head->val)
                return false;
            newHead=newHead->next;
            head=head->next;
        }
        return true;
    }
};
