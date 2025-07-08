/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};

        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int siz = q.size();
            vector<int> dummy;
            for(int i = 0; i<siz; i++) {
                Node* temp = q.front(); q.pop();
                dummy.push_back(temp->val);

                for (Node* it:temp->children) {
                    q.push(it);
                }
            }
            ans.push_back(dummy);
        }
        return ans;
    }
};