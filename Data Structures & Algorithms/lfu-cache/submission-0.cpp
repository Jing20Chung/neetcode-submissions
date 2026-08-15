class LFUCache {
    struct Node {
        Node(int k, int v): key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;
    };

    struct LinkedList {
        Node* head;
        Node* tail;
        int size;

        LinkedList () {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        ~LinkedList(){
            delete head;
            delete tail;
        }

        int length() {
            return size;
        }

        void pop(Node* node) {
            if (size == 0) return;
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
            node->next = nullptr;
            node->prev = nullptr;
            --size;
        }

        void pushRight(Node* node) {
            Node* prev = tail->prev;
            prev->next = node;
            node->prev = prev;
            tail->prev = node;
            node->next = tail;
            ++size;
        }

        Node* popLeft() {
            Node* node = head->next;
            pop(node);
            return node;
        }
    };

    unordered_map<int, Node*> nodeMap; // key, Node*
    unordered_map<int, LinkedList*> listMap; // freq, list
    
    int cap;
    int lfuCnt;

    void updateFreq(Node* node) {
        int freq = node->freq;
        listMap[freq]->pop(node);
        if (freq == lfuCnt && listMap[freq]->length() == 0) {
            ++lfuCnt;
        }
        node->freq++;
        if (!listMap.contains(node->freq)) {
            listMap[node->freq] = new LinkedList();
        }
        listMap[node->freq]->pushRight(node);
    }

public:
    LFUCache(int capacity): cap(capacity), lfuCnt(0) {
        
    }

    ~LFUCache () {
        for(auto[val, node]: nodeMap) {
            delete node;
        }

        for(auto[freq, linkedList]: listMap) {
            delete linkedList;
        }
    }
    
    int get(int key) {
        if (nodeMap.contains(key)) {
            Node* node = nodeMap[key];
            updateFreq(node);
            return node->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node* node;
        if (!nodeMap.contains(key)) {
            node = new Node(key, value);
            if (nodeMap.size() == cap) {
                Node* res = listMap[lfuCnt]->popLeft();
                nodeMap.erase(res->key);
                delete res;
            }

            nodeMap[key] = node;
            if (!listMap.contains(1)) {
                listMap[1] = new LinkedList();
            }
            listMap[1]->pushRight(node);
            lfuCnt = 1;
        }
        else {
            node = nodeMap[key];
            node->val = value;
            updateFreq(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */