/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return{};
        queue<Node*>q;
        q.push(node);
        unordered_map<Node*,Node*> m;
        Node *clone = new Node(node->val);
        m[node] = clone;
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            for(Node* temp : t->neighbors){
                if(m.count(temp)!=1){
                    q.push(temp);
                    m[temp] = new Node(temp->val);
                }
                m[t]->neighbors.push_back(m[temp]);
            }
        }
        return clone;
    }
};