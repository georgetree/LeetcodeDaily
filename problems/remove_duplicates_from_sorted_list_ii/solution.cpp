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
        ListNode* dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = head;
        while(pre->next){
            ListNode *temp = pre->next;
            while(temp->next && temp->val == temp->next->val)
                temp = temp->next;
            if(temp != pre->next) pre->next = temp->next; 
                //表示指標移動過，代表有重複的，將pre下個節點指向temp下個
                //temp只在下個不相等時while才跳開，所以temp的next一定不同
            else pre = pre->next;
        }
        return dummy->next;
    }
};