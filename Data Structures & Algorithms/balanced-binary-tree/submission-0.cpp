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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        unordered_map<TreeNode*, int> mp;
        stack<TreeNode*> stk;
        mp[nullptr] = 0;

        stk.push(root);
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            if (cur->left != nullptr && mp.find(cur->left) == mp.end()) {
                stk.push(cur->left);
            }
            else if (cur->right != nullptr && mp.find(cur->right) == mp.end()) {
                stk.push(cur->right);
            }
            else {
                stk.pop();
                int leftHeight = mp[cur->left];
                int rightHeight = mp[cur->right];

                if (std::abs(leftHeight - rightHeight) > 1) {
                    return false;
                }
                mp[cur] = max(leftHeight, rightHeight) + 1;
            }
        }
        return true;
    }
};
