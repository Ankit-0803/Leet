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
    TreeNode* buildBST(vector<int>& nums, int left, int right){
        int n=nums.size();
        if(left>right)return nullptr;
        //choose middle element as root for balalnce
        int mid=left+(right-left)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        //recursively build left and right subtree
        root->left=buildBST(nums, left, mid-1);
        root->right=buildBST(nums, mid+1, right);
        return root;
    };
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return buildBST(nums, 0, n-1);
    }
};