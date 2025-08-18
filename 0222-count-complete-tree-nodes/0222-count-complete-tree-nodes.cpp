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
    int treeheight(TreeNode* root){
        int height=0;
        while(root){
        height++;
        root=root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int leftheight=treeheight(root->left);
        int rightheight=treeheight(root->right);
        if(leftheight==rightheight){
            //leftsubtree is a perfect binary tree
            return (1<<leftheight)+countNodes(root->right);
        }
        else
        {
        return countNodes(root->left)+(1<<rightheight);  
        }     
    }
};