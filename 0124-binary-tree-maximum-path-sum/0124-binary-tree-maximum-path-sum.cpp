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
    int maxsumm=INT_MIN;
    int maxSum(TreeNode* node){
       if(node==nullptr)return 0;
        int leftgain=max(maxSum(node->left),0);
        int rightgain=max(maxSum(node->right),0);
        int currentSum=leftgain+rightgain+node->val;
         //update the global maxpathsum
        maxsumm=max(maxsumm, currentSum);
        //return the maximum gain from this node to its parent and also
        //it will decide the direction to continue with
        return node->val+max(leftgain, rightgain);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)return 0;
        maxSum(root);
        return maxsumm;
        
    }
};