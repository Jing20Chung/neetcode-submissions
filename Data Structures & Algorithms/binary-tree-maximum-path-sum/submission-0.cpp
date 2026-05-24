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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        searchMaxPath(root, maxSum);
        return maxSum;
    }
private:

    int searchMaxPath(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        int left = max(0, searchMaxPath(root->left, maxSum));
        int right = max(0, searchMaxPath(root->right, maxSum));

        int curSum = root->val + left + right;
        maxSum = max(curSum, maxSum);

        return root->val + max(left, right);
    }
};
