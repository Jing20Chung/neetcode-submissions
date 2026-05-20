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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *end = &dummy;

        while(end->next != nullptr) {
            for(int i = 0; i < k && end != nullptr; i++) {
                end = end->next;
            }
            if (end == nullptr) break;

            ListNode* start = prev->next;
            ListNode* nextGroup = end->next;

            end->next = nullptr;
            prev->next = reverse(start);
            start->next = nextGroup;
            prev = start;
            end = prev;
        }

        return dummy.next;
    }
private:
    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        while(head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
