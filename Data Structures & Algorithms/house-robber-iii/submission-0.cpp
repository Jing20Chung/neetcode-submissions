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
        dp.clear();
        return solve(root, 1);
    }

    int solve(TreeNode* node, int canRob) {
        if (!node) return 0;

        if (dp.contains(node)) {
            if (dp[node][canRob] != -1) {
                return dp[node][canRob];
            }
        }
        else {
            dp[node] = {-1, -1};
        }

        int profit = 0;
        // rob
        if (canRob == 1) {
            profit = node->val + solve(node->left, 0) + solve(node->right, 0);
        }
        // not rob
        profit = max(profit, solve(node->left, 1) + solve(node->right, 1));
        dp[node][canRob] = profit;
        return profit;
    }

    unordered_map<TreeNode*, vector<int>> dp;
};