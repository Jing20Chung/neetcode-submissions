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
    void dfs(TreeNode* root, vector<int>& ans, int depth) {
        if (!root) return;
        if (ans.size() == depth) ans.push_back(root->val);
        if (root->right) dfs(root->right, ans, depth + 1);
        if (root->left) dfs(root->left, ans, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};
