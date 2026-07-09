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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        int inorderIndex = inorderMap[rootVal];

        int leftSize = inorderIndex - inStart;

        TreeNode* node = new TreeNode(rootVal);
        node->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inorderIndex - 1, inorderMap);
        node->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inorderIndex + 1, inEnd, inorderMap);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1, inorderMap);
    }
};
