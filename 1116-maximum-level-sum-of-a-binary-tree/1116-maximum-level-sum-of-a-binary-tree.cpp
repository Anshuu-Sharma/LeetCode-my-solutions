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
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int ans_level;
        int level = 0;
        long long maxi = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            level++;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(maxi < sum) {
                    ans_level = level;
                    maxi = sum;
                }
        }
        return ans_level;
    }
};