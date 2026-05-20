struct Node {
    int key, val;
    Node* prev, *next;
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, Node*> lookup;
    Node *head, *tail;
    int cap;

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        auto it = lookup.find(key);
        if (it != lookup.end()) {
            Node* node = it->second;
            moveToHead(node);
            return node->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            if (lookup.size() >= cap) {
                Node* toRemove = tail->prev;
                removeNode(toRemove);
                lookup.erase(toRemove->key);
                delete toRemove;
            }

            Node* node = new Node(key, value);
            addNode(node);
            lookup[key] = node;
        }
        else {
            Node* node = it->second;
            node->val = value;
            moveToHead(node);
        }
    }
};
