class Solution {
public:
    int minSum = INT_MAX;
    int recursion(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        int down = INT_MAX;
        int right = INT_MAX;
        if(i+1<m) down = grid[i][j] + recursion(i+1, j, m,n, grid);
        if(j+1<n) right = grid[i][j] + recursion(i, j+1, m, n, grid);

        return min(down, right);
    }
    int tabulation(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = grid[m-1][n-1];

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;
                int down = INT_MAX;
                int right = INT_MAX;
                if(i+1<m) down = grid[i][j] + dp[i+1][j];
                if(j+1<n) right = grid[i][j] + dp[i][j+1];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return recursion(0,0,m,n,grid);
        return tabulation(grid);
    }
};