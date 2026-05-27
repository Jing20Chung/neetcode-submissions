class Node {
public:
    Node(char c) {
        this->c = c;
        isWord = false;
    }
    char c;
    Node* next[26] = {nullptr};
    bool isWord;

};

class PrefixTree {
public:
    PrefixTree() {
        head = new Node(' ');
    }
    ~PrefixTree() {
        clear(head);
    }
    
    void insert(string word) {
        int idx = 0;
        Node* cur = head;
        while (idx < word.size()) {
            char c = word[idx];
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new Node(c);
            }
            cur = cur->next[c - 'a'];
            idx++;
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        int idx = 0;
        Node* cur = head;
        while (idx < word.size()) {
            char c = word[idx];
            if (!cur->next[c - 'a']) {
                return false;
            }
            cur = cur->next[c - 'a'];
            idx++;
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        int idx = 0;
        Node* cur = head;
        while (idx < prefix.size()) {
            char c = prefix[idx];
            if (!cur->next[c - 'a']) {
                return false;
            }
            cur = cur->next[c - 'a'];
            idx++;
        }
        return true;
    }
private:
    Node* head;
    void clear(Node* node) {
        for(int i = 0; i < 26; i++) {
            if (node->next[i]) {
                clear(node->next[i]);
            }
        }
        delete node;
    }
};
