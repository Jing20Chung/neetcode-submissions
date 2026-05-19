/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        // find the middle point first
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // at this point, slow is at the middle of the list.
        // reverse the list after slow
        ListNode* newHead = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(newHead) {
            ListNode* nxt = newHead->next;
            newHead->next = prev;
            prev = newHead;    
            newHead = nxt;
        }

        // now, newHead is the reversed slow list's head
        // start reorder the list
        ListNode* origin = head;
        newHead = prev;
        while(newHead) {
            ListNode* tmp1 = origin->next;
            ListNode* tmp2 = newHead->next;
            origin->next = newHead;
            newHead->next = tmp1;
            origin = tmp1;
            newHead = tmp2;
        }
    }
};
