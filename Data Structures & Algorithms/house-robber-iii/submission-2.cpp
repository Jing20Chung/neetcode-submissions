/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // 13:14
class Solution {
public:
    int rob(TreeNode* root) {
        auto [robProfit, notRobProfit] = solve(root);
        return max(robProfit, notRobProfit);
    }

    pair<int, int> solve(TreeNode* node) {
        if (!node) return {0, 0};
        auto [leftRob, leftNotRob] = solve(node->left);
        auto [rightRob, rightNotRob] = solve(node->right);

        int robProfit = node->val + leftNotRob + rightNotRob;
        int notRobProfit = max(leftRob, leftNotRob) + max(rightRob, rightNotRob);
        return {robProfit, notRobProfit};
    }
};