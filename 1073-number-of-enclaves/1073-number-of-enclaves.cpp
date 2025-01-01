class Solution {
public:

    void dfs(vector<vector<int>>& grid, int drow[], int dcol[],vector<vector<int>>& vis, int r, int c){
        for(int i = 0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == 1 && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                dfs(grid, drow, dcol, vis, nr, nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));

        //Checking first and last row for 1s
        for(int i = 0; i<n; i++){
            if(grid[0][i] == 1) dfs(grid, drow, dcol, vis, 0, i);
            if(grid[m-1][i] == 1) dfs(grid, drow, dcol, vis, m-1, i);
        }

        //Checking first and last column for 1s
        for(int i = 0; i<m; i++){
            if(grid[i][0] == 1)  dfs(grid, drow, dcol, vis, i, 0);
            if(grid[i][n-1] == 1) dfs(grid, drow, dcol, vis, i, n-1);
        }

        for(int i = 1; i<m-1; i++){
            for(int j = 1; j<n-1; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vis[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};