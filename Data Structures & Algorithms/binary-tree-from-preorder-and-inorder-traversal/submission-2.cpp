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
    int preIndex;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        int mid = inorderMap[rootVal];

        TreeNode* node = new TreeNode(rootVal);
        node->left = build(preorder, inorder, inStart, mid - 1, inorderMap);
        node->right = build(preorder, inorder, mid + 1, inEnd, inorderMap);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        preIndex = 0;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, inorderMap);
    }
};
