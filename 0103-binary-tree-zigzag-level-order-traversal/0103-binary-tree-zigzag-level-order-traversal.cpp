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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> qs;
        qs.push(root);
        bool ltr = 1;
        
        while(!qs.empty()) {
            int size1 = qs.size();
            vector<int> row(size1);
            for(int i = 0; i<size1; i++) {
                    TreeNode* temp = qs.front();
                    qs.pop();
                    int index = ltr ? i : (size1 - 1 - i);
                    row[index] = temp->val;
            

                    if(temp->left) qs.push(temp->left);
                    if(temp->right) qs.push(temp->right);

            }
                    ltr = !ltr;
                    result.push_back(row);
        }
            return result;
    }
};