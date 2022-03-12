/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *t = head;
        while(t){
            Node *newNode = new Node(t->val);
            newNode->next = t->next;
            t->next = newNode;
            t = t->next->next;
        }
        // 1,1',2,2',3,3'
        t = head;
        while(t){
            if(t->random)
                t->next->random = t->random->next;
            t = t->next->next;
        }
        t = head;
        Node *res = head->next;
         
        while(t){
            Node *resNode = t->next;
            t->next = t->next->next;  
            if(resNode->next) resNode->next = resNode->next->next;
            t = t->next;
        }
        return res;
    }
};