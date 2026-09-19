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
    int dfs(TreeNode* root){
        if(!root)return 0;
        int leftH = dfs(root->left);
        int rightH = dfs(root->right);
        //when not balanced
        if(leftH == -1)return -1;
        if(rightH == -1)return -1;
        if(abs(leftH-rightH)>1)return -1;
        //return height when tree is balanced uptill current node
        return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)>-1;        
    }
};
