class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int i, Node *n): val(i), next(n){}
    };
    Node *head, *tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node *cur = head;
        for(int i=0; i<index; i++)
            cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node *t = new Node(val,head);
        head = t;
        if(size==0) tail = t;
        ++size;
    }
    
    void addAtTail(int val) {
        Node *t = new Node(val,nullptr);
        if(size==0){
            head = t;
            tail = t;
        } 
        tail->next = t;
        tail = t;
        ++size;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index <=0) {
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        Node *t = head;
        for(int i=0; i<index-1; i++)
            t = t->next;
        Node *newNode = new Node(val,t->next);
        t->next = newNode;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0){
            head = head->next;
            --size;
            return;
        }
        Node *t = head;
        for(int i=0; i<index-1; i++){
            t = t->next;
        }
        t->next = t->next->next;
        if(index == size-1) tail = t;
        --size;
    }
    // void debug() {
    //   Node *iter = head;
    //   while (iter) {
    //     std::cout << iter->val << "->";
    //     iter = iter->next;
    //   }
    //   std::cout << ": " << size << std::endl;
    // }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */