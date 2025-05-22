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
    TreeNode* TreeBuilder(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp){
        if(postStart>postEnd || inStart>inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root->val];
        int siz =  inRoot - inStart;
        root->left = TreeBuilder(postorder, postStart, postStart + siz - 1, inorder, inStart, inRoot-1, mpp);
        root->right = TreeBuilder(postorder, postStart+siz, postEnd-1, inorder, inRoot+1, inEnd, mpp);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // map for inorder elements- so that we can easily get the element's index 
        map<int, int> mpp;
        for(int i = 0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

       return TreeBuilder(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        
    }
};