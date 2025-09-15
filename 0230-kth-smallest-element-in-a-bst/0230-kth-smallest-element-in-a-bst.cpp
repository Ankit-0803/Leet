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
    int count=0;
    int res=-1;
    void kth(TreeNode* root, int k){
        if(root==nullptr)return;
        //traverse left subtree
        kth(root->left, k);
        count++;
        if(count==k){
            res=root->val;
            return;
        }
        //traverse right subtree
        kth(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        kth(root, k);
        return res;
        
    }
};