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
    unordered_map<int, int> mpp;  // Map value -> index for inorder
    int postIndex;                         // Tracks root in postorder

    // Helper function
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        // Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        // Find position of root in inorder
        int inPos = mpp[rootVal];
        // Important: build right subtree first (postorder = L R Root)
        root->right = build(inorder, postorder, inPos + 1, inEnd);
        root->left = build(inorder, postorder, inStart, inPos - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Build hashmap for inorder index lookup
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;  // Start from last element of postorder
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
