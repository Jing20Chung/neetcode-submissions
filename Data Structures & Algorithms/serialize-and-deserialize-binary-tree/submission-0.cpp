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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output = "";
        encode(root, output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return decode(pos, data);
    }
private:
    void encode(TreeNode* root, string& output){
        if (!root) {
            output += "#,";
            return;
        }

        output += to_string(root->val) + ",";

        encode(root->left, output);
        encode(root->right, output);
    }

    TreeNode* decode(int& pos, const string& data) {
        if (pos >= data.size()) return nullptr;

        int nextPos = data.find(',', pos);
        string val = data.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(pos, data);
        node->right = decode(pos, data);
        return node;
    }
};
