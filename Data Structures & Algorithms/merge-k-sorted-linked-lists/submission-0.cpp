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
    struct Compare {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(ListNode* list: lists) {
            if(list != nullptr) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next != nullptr) {
                pq.push(cur->next);
            }
        }
        return dummy.next;
    }
};
