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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()<1)
            return 0;
        ListNode *result = lists[0]; // return linked list
        for(int i=1; i<lists.size(); i++){
                result = mergetwoLists(result,lists[i]);    
            }
        return result;
        }
    
    ListNode* mergetwoLists(ListNode *a, ListNode *b) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(a && b){
            if(a->val > b->val){
                cur->next = b;
                b = b->next;
            }else{
                cur->next = a;
                a = a->next;
            }
            cur = cur->next;
        }
        cur->next = a == nullptr ? b : a;
        return head->next;
    }
};
 