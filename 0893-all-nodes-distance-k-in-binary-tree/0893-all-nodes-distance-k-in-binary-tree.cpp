/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) 
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->left) 
            {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right)
            {
                parent_track[current->right] = current;
                q.push(current->right);
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {       ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            
            unordered_map<TreeNode*, TreeNode*> parent_track;
            markParents(root, parent_track, target);

            unordered_map<TreeNode*, bool> visited;
            queue<TreeNode*> q;
            q.push(target);
            visited[target] = true;
            int curr_level = 0;

            while( !q.empty() )
            {
                int size1 = q.size();

                if( curr_level++ == k ) break;

                for( int i = 0; i < size1; i++ ) 
                {
                    TreeNode* current = q.front();q.pop();
                    if( current->left && !visited[current->left] )  
                    {
                        q.push(current->left);
                        visited[current->left] = true;
                    }
                    if( current->right && !visited[current->right] ) 
                    {
                        q.push(current->right);
                        visited[current->right] = true;
                    }

                    if( parent_track[current] && !visited[parent_track[current]] ) 
                    {
                        q.push(parent_track[current]);
                        visited[parent_track[current]] = true;
                    }
                }
            }

            vector<int> res;
            while( !q.empty() )
            {
                TreeNode* current = q.front(); q.pop();
                res.push_back(current->val);
            }
            return res;
    }
};