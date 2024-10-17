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
    // ITERATIVE
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            ans.push_back(temp->val);
        }
        return ans;



















    }
    // void preorder(TreeNode* root, vector<int>& arr) {
    //     if(root == NULL) return;

    //     arr.push_back(root->val);
    //     preorder(root->left, arr);
    //     preorder(root->right, arr);
    // }
   
    // vector<int> preorderTraversal(TreeNode* root) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(nullptr);
        
    //     vector<int> arr;
    //     preorder(root, arr);

    //     return arr;
    // }
};