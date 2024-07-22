/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        int cur = root->val;

        if(cur < p->val && cur < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(cur > p->val && cur > q->val) 
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};