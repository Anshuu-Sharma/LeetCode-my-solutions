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
private:
    int cnt = 0;

public:
    void traverse(TreeNode* root, int m){
        if(!root) return;
        if(root->val >= m){
           m = root->val;
           cnt++;
        }
        
        traverse(root->left, m);
        traverse(root->right, m);
    }

    int goodNodes(TreeNode* root) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);

        int m = INT_MIN;
        traverse(root, m);
        return cnt;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();