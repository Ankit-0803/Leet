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
    unordered_map<int, int>mpp; //store value->index in order
    int preindex=0;   //to track the root in preorder
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int instart, int inend){
     //base case
     if(instart>inend)return nullptr;
     //get the root value from preorder
     int rootval=preorder[preindex++];
     TreeNode* root=new TreeNode(rootval);

     //find the index of root in inorder
     int inindex= mpp[rootval];


     //build the left and right subtree
     root->left= build(preorder, inorder, instart, inindex-1);
     root->right= build(preorder, inorder, inindex+1, inend);
     return root;
    }

  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //prorder tells us the order in which to create roots
        //inorder tells how to split the left and right subtree
        //populate the hashmap
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};