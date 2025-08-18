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
    void flatten(TreeNode* root) {
        if(!root)return;
        //step1-flatten left and right subtree
        flatten(root->left);
        flatten(root->right);
        //step2- store the right subtree & move leftsubtree to the right
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        //step3- find the tail starting from root(works even when left is null)
        TreeNode* curr=root;
        while(curr->right){
            curr=curr->right;
        }
         //step4- attach saved right subtree
        curr->right=temp;
         
    }
};