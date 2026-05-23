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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1, inorderMap);
    }
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int rootIndex = inorderMap[node->val];
        int leftSize = rootIndex - inStart;

        node->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1, inorderMap);
        node->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderMap);
        return node;
    }
};
