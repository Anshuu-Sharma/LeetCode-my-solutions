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
    map<int, int> mpp;
    int n = 0;

public:
    void traverse(TreeNode* root, int level){
        if(!root) return;

        if(mpp.find(level) == mpp.end()){
            mpp[level] = root->val;
            n++;
        }

        traverse(root->left, level+1);
        traverse(root->right, level+1);

    }


    int findBottomLeftValue(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        traverse(root, 0);
        return mpp[n-1];
    }
};