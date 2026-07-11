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
    int pairSum(ListNode* head) {
        vector<int> sum;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            sum.push_back(slow->val);
            slow = slow->next;
        }
        int maxSum = INT_MIN;
        auto i = std::ssize(sum) - 1;
        for (i; i >= 0; --i) {
            sum[i] += slow->val;
            slow = slow->next;
            maxSum = max(maxSum, sum[i]);
        }
        return maxSum;
    }
};