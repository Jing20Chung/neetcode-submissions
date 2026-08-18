class LinkedList {
private:
    struct Node {
        Node(int val): val(val), next(nullptr) {}
        Node* next;
        int val;
    };

    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    int get(int index) {
        Node* cur = head->next;
        int i = 0;
        while (cur != nullptr) {
            if (i == index) return cur->val;
            cur = cur->next;
            ++i;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if (tail == head) tail = newNode;
    }
    
    void insertTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        Node* cur = head;
        int i = 0;
        while (i < index && cur != nullptr) {
            cur = cur->next;
            ++i;
        }

        if (cur != nullptr && cur->next != nullptr) {
            if (cur->next == tail) tail = cur;
            Node* toDelete = cur->next;
            cur->next = cur->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* cur = head->next;
        while (cur != nullptr) {
            ans.push_back(cur->val);
            cur = cur->next;
        }
        return ans;
    }
};
