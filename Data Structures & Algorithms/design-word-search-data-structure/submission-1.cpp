class WordDictionary {
public:
    WordDictionary(): root(new Node()) {
        
    }

    ~WordDictionary() {
        clear(root);
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(const char c: word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        if (word.size() == 0) return false;
        return dfs(0, word, root);
    }
private:
    struct Node {
        Node(): isWord(false){}
        unordered_map<char, Node*> children;
        bool isWord;
    };

    Node* root;

    bool dfs(int index, const string& word, Node* node) {
        if (index == word.size()) return node->isWord;
        const char c = word[index];
        if (c == '.') {
            for(auto it = node->children.begin(); it != node->children.end(); ++it) {
                if (dfs(index + 1, word, it->second)) return true;
            }
        }
        else {
            if (node->children.contains(c) && dfs(index + 1, word, node->children[c])) return true;
        }
        return false;
    }

    void clear(Node* node){
        for(auto it = node->children.begin(); it != node->children.end(); ++it) {
            clear(it->second);
        }
        delete node;
    }
};
