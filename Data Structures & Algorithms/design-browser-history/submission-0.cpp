// I will create a doubled linked list for this problem
// starting from the homepage, if the user go visit url
// new a node for that url
// store old next node's pointer
// set next node to the node
// assign prev of the node to the current node
// and move current node to the new node.
// delete all the next node chain

//          0->1->2->3->nullptr
// nullptr<-
//.            cur
//.             ->4->5->nullptr
class BrowserHistory {
private:
    struct Node {
        Node(string _url = "", Node* _prev = nullptr, Node* _next = nullptr):
        url(_url), prev(_prev), next(_next){}
        string url;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* cur;

    void deleteAllNode(Node* ptr) {
        while(ptr != nullptr) {
            Node* cur = ptr;
            ptr = ptr->next;
            delete cur;
        }
    }
public:
    BrowserHistory(string homepage) {
        cur = new Node(homepage);
        head = cur;
    }

    ~BrowserHistory() {
        deleteAllNode(head);
    }
    
    void visit(string url) {
        deleteAllNode(cur->next);

        cur->next = new Node(url);
        cur->next->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        while(steps > 0 && cur->prev != nullptr) {
            cur = cur->prev;
            steps--;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(steps > 0 && cur->next != nullptr) {
            cur = cur->next;
            steps--;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */