class MyLinkedList {
private:
    struct Node {
        Node(int _val = 0, Node* _next = nullptr, Node* _prev = nullptr): val(_val), next(_next), prev(_prev) {}
        int val;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int size;

    Node* getPrev(int index) {
        Node* cur;
        if (index <= size/2) {
            cur = head;
            for(int i = 0; i < index; i++) {
                cur = cur->next;
            }
        }
        else {
            cur = tail;
            for(int i = size; i >= index; i--) {
                cur = cur->prev;
            }
        }
        return cur;
    }
public:
    MyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* prev = getPrev(index);
        return prev->next->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* prev = getPrev(index);
        Node* next = prev->next;
        Node* node = new Node(val, next, prev);
        next->prev = node;
        prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* prev = getPrev(index);
        Node* del = prev->next;
        Node* next = del->next;
        prev->next = next;
        next->prev = prev;
        delete del;
        size--;
    }
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