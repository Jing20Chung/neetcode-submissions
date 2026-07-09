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
        // calculate all children's height, then decide whether the tree is balanced.
        // to store the height, I need a dictionary to store those values.
        // I'll also need a stack to track all unprocessed nodes
        // when popping from the stack, all the children of that node should already has value in the 
        // dictionary.

        // if the node is not null
        // push it into stack and move to the left child
        // else if the node is null, means there is no left child or right child
        // get one node from the stack (move back to the parent node)
        // and see if it has right child or the right child has been processed
        // if it doesn't have a right child or the right child has been processed
        // means we can calculate it's height
        // if it has a right child, push this node into stack and move to the right child
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, int> heightMap;
        heightMap[nullptr] = 0;
        TreeNode* curr = root;

        while(curr != nullptr || !stk.empty()) {
            if (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                curr = stk.top();
                if (curr->right == nullptr || heightMap.find(curr->right) != heightMap.end()) {
                    int left = heightMap[curr->left];
                    int right = heightMap[curr->right];
                    if (abs(left - right) > 1) return false;
                    else {
                        heightMap[curr] = 1 + max(left, right);
                    }
                    stk.pop();
                    curr = nullptr;
                }
                else {
                    curr = curr->right;
                }
            }
        }
        return true;
    }
};
