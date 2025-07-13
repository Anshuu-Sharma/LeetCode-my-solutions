class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, vector<int>& vis, int startNode){
        for(int i = 0; i<n; i++){
            if(isConnected[startNode][i] && !vis[i]){
                vis[i] = 1;
                dfs(isConnected, n, vis, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int numOfProvinces = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(isConnected, n, vis, i);
            numOfProvinces++;
        }
    }
    return numOfProvinces;
    }
};