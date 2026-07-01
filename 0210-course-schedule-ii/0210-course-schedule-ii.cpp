class Solution {
private:
    vector<int> ans;
    bool hasCycle = false;

public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        if (hasCycle) return;
        
        vis[node] = 1; // Mark as 'currently visiting' in the current path

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                dfs(it, vis, adj);
            } else if (vis[it] == 1) {
                // If we hit a node that is currently in our DFS path, a cycle exists
                hasCycle = true; 
                return;
            }
        }

        vis[node] = 2; // Mark as 'fully visited' and safe
        ans.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 0 = unvisited, 1 = visiting, 2 = completely visited
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        ans.clear();

        // Build adjacency list
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v); // u must be taken before v
        }

        // Run DFS on all unvisited nodes
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, adj);
            }
        }

        // If a cycle is detected, no valid schedule exists
        if (hasCycle) return {}; 

        // DFS gives reverse topological sort, so we reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};