class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if(preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root in inorder
        int i = inStart;

        while(inorder[i] != root->val) {
            i++;
        }

        // Number of nodes in left subtree
        int leftSize = i - inStart;

        // Build left subtree
        root->left = solve(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           i - 1);

        // Build right subtree
        root->right = solve(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            i + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty() || inorder.empty())
            return nullptr;

        return solve(preorder, inorder,
                     0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};