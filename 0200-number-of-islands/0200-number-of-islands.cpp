class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int drow[], int dcol[]){
        vis[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, vis, grid, drow, dcol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        int cnt = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
       
                        dfs(i,j,vis,grid,drow,dcol);
                        cnt++;
             
                }
            }
        } 
        return cnt;
    }
};