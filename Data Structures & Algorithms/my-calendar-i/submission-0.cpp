class Tree {
public:
    Tree(int startTime, int endTime): s(startTime), e(endTime), left(nullptr), right(nullptr) {}
    ~Tree(){
        delete left;
        delete right;
    }
    int s;
    int e;
    Tree* left;
    Tree* right;

    bool insert(int startTime, int endTime) {
        Tree* curr = this;
        while (1) {
            if (curr->s >= endTime) {
                if (curr->left == nullptr) {
                    curr->left = new Tree(startTime, endTime);
                    return true;
                }
                curr = curr->left;
            }
            else if (curr->e <= startTime) {
                
                if (curr->right == nullptr) {
                    curr->right = new Tree(startTime, endTime);
                    return true;
                }
                curr = curr->right;
            }
            else {
                return false;
            }
        }
        return false;
    }
};

class MyCalendar {
    Tree* tree;
public:
    MyCalendar(): tree(nullptr) {
    }
    ~MyCalendar(){
        delete tree;
    }
    
    bool book(int startTime, int endTime) {
        if (tree == nullptr) {
            tree = new Tree(startTime, endTime);
            return true;
        }
        return tree->insert(startTime, endTime);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */