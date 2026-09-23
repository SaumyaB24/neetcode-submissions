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
    void serializeHelper(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }
    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');

        if (val == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

