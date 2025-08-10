/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr; // Base Case 1: If root is null, return null
        // Base Case 2: If root is equal to either p or q, return root
        // This means we've found one of the nodes
        if(p==root || q==root)return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        // Case 1: p and q are found in different subtrees
        // That means current root is their lowest common ancestor
        if(left && right)return root;
        // Case 2: Both p and q are in the left subtree → return left
        //: Both p and q are in the right subtree ->return right
        return left?left:right;

        }
};