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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        //recursively invert the left and right subtree
        TreeNode* leftSubtree= invertTree(root->left);
        TreeNode* rightSubtree= invertTree(root->right);
        //swsap left and right children
        root->left=rightSubtree;
        root->right=leftSubtree;
        return root;
        
    }
};