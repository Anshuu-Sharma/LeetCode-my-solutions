class Solution {
public:
    int ans=0;
    
    void countPaths(TreeNode* root, unordered_set<int>s){
        if(s.find(root->val)!=s.end()) s.erase(root->val);
        else s.insert(root->val);
        if(!root->left && !root->right) {
            if(s.size()<=1) ans++;
            return;
        }
        if(root->left) countPaths(root->left,s);
        if(root->right) countPaths(root->right,s);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
       if(!root) return 0;
        unordered_set<int> s;
        countPaths(root,s);
        return ans;
    }
};