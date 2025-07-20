class Solution {
public:
    int dfs(vector<vector<int>>& grid, int sr, int sc, vector<vector<int>>& vis) {
        vis[sr][sc] = 1;
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i<4; i++) {
            int nr = sr + drow[i];
            int nc = sc + dcol[i];

            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] != 0 && !vis[nr][nc]){
                maxGold = max(maxGold, dfs(grid, nr, nc, vis));
            }
        }
        vis[sr][sc] = 0;
        return maxGold + grid[sr][sc];
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MIN;
        for(int i = 0; i<m; i++){
            for(int j = 0;  j<n; j++){
                if(grid[i][j]==0) continue;
                vector<vector<int>> vis(m, vector<int>(n, 0));
                ans = max(ans, dfs(grid, i, j,vis));
            }
        }

        return ans == INT_MIN ? 0 : ans;
    }
};