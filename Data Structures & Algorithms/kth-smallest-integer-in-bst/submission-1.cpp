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
private:
    void inorder(TreeNode* root, int& rank, int& k, int& result) {
        if (!root || rank >= k) return;
        inorder(root->left, rank, k, result);
        if (rank >= k) return;

        rank++;
        if (rank == k) {
            result = root->val;
            return;
        }

        inorder(root->right, rank, k, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        int ans = 0;
        inorder(root, rank, k, ans);
        return ans;
    }
};
