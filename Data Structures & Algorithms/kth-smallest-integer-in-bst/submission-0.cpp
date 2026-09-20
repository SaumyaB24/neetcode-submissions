class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int n = 0;

        // Inorder traversal of BST
        while (curr || !st.empty()) {

            // Go as far left as possible
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();

            n++;

            if (n == k)
                return curr->val;

            // Explore right subtree
            curr = curr->right;
        }
        return -1; 
    }
};