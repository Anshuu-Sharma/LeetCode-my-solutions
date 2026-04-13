class Solution {
public:
    void dfs(int i, int j, int m, int n, int &area, vector<vector<int>>& visited, vector<vector<int>>& grid){
        visited[i][j] = 1;
        area++;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int k = 0; k<4; k++){
            int nr = i + drow[k];
            int nc = j + dcol[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, m, n, area, visited, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        vector<vector<int>> visited(m ,vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int area = 0;
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    dfs(i, j, m, n, area, visited, grid);
                }
                ans = max(ans, area);
            }
        }

        return ans;
    }
};