class Solution {
public:
    void dfs(int idx, vector<vector<int>>& isConnected, vector<int>& visited){
        visited[idx] = 1;
        int n = isConnected.size();

        for(int i = 0; i<n; i++){
            if(idx != i && visited[i] == 0 && isConnected[idx][i]){
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(visited[i] == 0) {
                dfs(i, isConnected, visited);
                ans++;
            }
        }

        return ans;
    }
};