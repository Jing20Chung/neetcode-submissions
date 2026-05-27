class Node {
public:
    Node() {}
    Node(char c) {
        this->c = c;
    }
    ~Node(){}

    char c;
    Node* next[26] = {nullptr};
    bool isWord = false;
};

class WordDictionary {
public:
    WordDictionary() {
        head = new Node();
    }
    ~WordDictionary(){
        clear(head);
    }
    
    void addWord(string word) {
        int idx = 0;
        Node* cur = head;
        while(idx < word.size()) {
            char c = word[idx];
            if(!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new Node(c);
            }
            cur = cur->next[c - 'a'];
            idx++;
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(0, word, head);
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

    bool dfs(int i, string& word, Node* node) {
        if (i >= word.size()) {
            return node->isWord;
        }

        char c = word[i];
        if (c == '.') {
            for(int j = 0; j < 26; j++) {
                if (node->next[j] && dfs(i + 1, word, node->next[j])) return true;
            }
        }
        else {
            if (node->next[c - 'a'] && dfs(i + 1, word, node->next[c - 'a'])) return true;
        }
        return false;
    }
};
