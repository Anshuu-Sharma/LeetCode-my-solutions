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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       // map<x-coordinate, map<y-coordinate, multiset of nodes at (x, y)>>
        map<int, map<int, multiset<int>>> nodes;
        // queue storing pairs of (TreeNode*, pair<x, y>)
        queue<pair<TreeNode*, pair<int, int>>> info;
        // start BFS with root at position (0, 0)
        info.push({root, {0, 0}});

        while(!info.empty()) {
            auto p = info.front();
            info.pop();
            TreeNode* temp = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(temp->val);

            if(temp->left) {
                info.push({temp->left, {x-1, y+1}});
            }

            if(temp->right) {
                info.push({temp->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(move(col));
        }
        return ans;


    }
};