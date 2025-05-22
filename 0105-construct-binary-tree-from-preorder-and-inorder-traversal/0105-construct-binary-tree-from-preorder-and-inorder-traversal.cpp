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
    TreeNode* TreeBuilder(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp){
        if(preStart>preEnd || inStart>inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mpp[root->val];
        int siz =  inRoot - inStart;
        root->left = TreeBuilder(preorder, preStart+1, preStart + siz, inorder, inStart, inRoot-1, mpp);
        root->right = TreeBuilder(preorder, preStart+siz+1, preEnd, inorder, inRoot+1, inEnd, mpp);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map for inorder elements- so that we can easily get the element's index 
        map<int, int> mpp;
        for(int i = 0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = TreeBuilder(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};