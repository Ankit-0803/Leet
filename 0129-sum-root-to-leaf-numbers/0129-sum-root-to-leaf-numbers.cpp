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
    int dfs(TreeNode* node, int current){
        if(!node)return 0;
        // Build number: shift left (multiply by 10) and add current digit
        current=current*10+node->val;
        //If it's a leaf, return the formed number
        if(!node->left && !node->right){
            return current;
        }
        return dfs(node->left, current)+dfs(node->right, current);
    }
    int sumNumbers(TreeNode* root) {
         return dfs(root, 0);
        
    }
};