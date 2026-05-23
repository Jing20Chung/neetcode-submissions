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
    void inorder(TreeNode* root, int& count, int k, int& result) {
        if (!root || count >= k) return;
        inorder(root->left, count, k, result);

        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorder(root->right, count, k, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int count = 0;
        inorder(root, count, k, res);
        return res;
    }
};
