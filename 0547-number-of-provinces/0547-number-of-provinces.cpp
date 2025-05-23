class Solution {
public:
    void dfs(int node,  vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);

        // Adjacency list making
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};