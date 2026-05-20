/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* cur = head;
        while(cur) {
            Node* oNext = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = oNext;
            cur = cur->next->next;
        }
        cur = head;
        while(cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        Node* copyHead = cur->next;
        Node* copyCur = copyHead;
        while(cur) {
            cur->next = cur->next->next;
            cur = cur->next;

            if(copyCur->next) {
                copyCur->next = copyCur->next->next;
                copyCur = copyCur->next;
            }
        }

        return copyHead;
    }
};
