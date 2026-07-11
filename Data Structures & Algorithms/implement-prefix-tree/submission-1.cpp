class PrefixTree {
private:
    struct Node {
        Node(): isWord(false), children(vector<std::unique_ptr<Node>>(26)) {}
        vector<std::unique_ptr<Node>> children;
        bool isWord;
    };
    std::unique_ptr<Node> root;
public:
    PrefixTree(): root(std::make_unique<Node>()) {
    }
    
    void insert(string word) {
        Node* curr = root.get();
        for(const char c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = std::make_unique<Node>();
            }
            curr = curr->children[index].get();
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root.get();
        for(const char c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index].get();
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root.get();
        for(const char c: prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index].get();
        }
        return true;
    }
};
