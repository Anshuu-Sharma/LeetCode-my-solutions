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
    void helper(vector<TreeNode*> arr){
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            int temp = arr[i]->val;
            arr[i]->val = arr[j]->val;
            arr[j]->val = temp;
            i++;j--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            int n = q.size();
            level++;
            vector<TreeNode*> store;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level%2) store.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(level%2){
                helper(store);
            }
        }
        return root;
    }
};