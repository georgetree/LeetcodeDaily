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
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }  
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto l: lists){
            if(l) pq.push(l);
        }
        
        ListNode *res = nullptr;
        ListNode **p = &res;
        
        while(!pq.empty()){
            *p = pq.top(); 
            pq.pop();
            if((*p)->next) pq.push((*p)->next);
            p = &(*p)->next;
        }
        return res;
    }
};