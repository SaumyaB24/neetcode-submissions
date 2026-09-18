class Solution {
public:
    int dfs(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int leftHeight = dfs(root->left, ans);
        int rightHeight = dfs(root->right, ans);
        ans = max(ans, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};