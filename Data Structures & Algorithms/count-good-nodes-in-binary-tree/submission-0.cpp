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
    int countGoodNodes(TreeNode* root, int maxi) {
        if (!root) return 0;
        int newMax = max(maxi, root->val);
        int count = (root->val >= maxi);
        count += countGoodNodes(root->left, newMax);
        count += countGoodNodes(root->right, newMax);
        return count;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }
};