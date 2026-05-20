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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* cur = head;
        int remain = k;
        while(cur != nullptr && remain > 0) {
            cur = cur->next;
            remain--;
        }

        ListNode* newHead = head;
        if (remain == 0) {
            ListNode* prev = nullptr;
            ListNode* start = head;
            for(int i = 0; i < k; i++) {
                ListNode* next = start->next;
                start->next = prev;
                prev = start;
                start = next;
            }
            newHead = prev;

            ListNode* nextHead = reverseKGroup(cur, k);
            head->next = nextHead;
            return newHead;
        }
        else {
            return head;
        }
    }
};
