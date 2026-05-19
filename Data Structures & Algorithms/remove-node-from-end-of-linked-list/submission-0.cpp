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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        ListNode* cur = &dummy;
        while(fast) {
            cur = cur->next;
            fast = fast->next;
        }
        ListNode* toRemove = cur->next;
        cur->next = cur->next->next;
        toRemove->next = nullptr;
        toRemove = nullptr;
        return dummy.next;
    }
};
