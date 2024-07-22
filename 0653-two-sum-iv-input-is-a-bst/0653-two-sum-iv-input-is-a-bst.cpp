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
 class BSTiterator {
public:
    stack<TreeNode*> mystack;
    bool reverse = true;
    
    BSTiterator(TreeNode* root, bool isreverse){
        reverse = isreverse;
        pushAll(root);
    }

    bool hasnext(){
        return !mystack.empty();
    }

    int next(){
        TreeNode* temp = mystack.top();
        mystack.pop();

        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    void pushAll(TreeNode* root){
        for(; root != NULL; ) {
            mystack.push(root);
            if(reverse == true){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
  
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};