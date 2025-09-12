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
    int preindex=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int instart, int inend, unordered_map<int, int>& mpp){
    if(instart>inend)return nullptr;
    int rootval=preorder[preindex++];
    TreeNode* root=new TreeNode(rootval);
    //find the index of root in inorder, and separate left and right subtree accordingly
    int inindex=mpp[rootval];
    root->left=build(preorder, inorder, instart, inindex-1, mpp);
    root->right=build(preorder, inorder, inindex+1, inend, mpp);
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        unordered_map<int, int>mpp; 
        int n=inorder.size();
        for(int i=0; i<n; i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder, inorder, 0, n-1, mpp);
    }
};